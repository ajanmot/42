/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoblech <hsoblech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 15:39:47 by hsoblech          #+#    #+#             */
/*   Updated: 2018/03/31 02:19:02 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int		check_file_champ(char *arg)
{
	if (open(arg, O_RDONLY) < 1)
	{
		ft_printf("File doesn't exist\n");
		return (0);
	}
	return (1);
}

static int		parse_one_arg_value(int last, char *arg, char **value)
{
	if (last == OPTION_DUMP)
	{
		*value = arg;
		return ((!is_number(arg) || ft_atoi(arg) < 1) ? 0 : OPTION_DUMP_V);
	}
	else if (last == OPTION_ID_PLAYER)
	{
		*value = arg;
		return ((!is_number(arg) || ft_atoi(arg) < 0) ? 0 : OPTION_ID_V);
	}
	else if (last == OPTION_VERBOSE)
	{
		*value = arg;
		return ((ft_atoi(arg) <= 0 || ft_atoi(arg) > 15) ? 0 : OPTION_VERB_V);
	}
	else if (check_file_champ(arg))
	{
		*value = arg;
		return (OPTION_FILE_PLAYER);
	}
	return (0);
}

static int		parse_one_arg(int last, char *arg, char **value)
{
	if (!ft_strcmp(arg, "-dump"))
	{
		if (last == OPTION_DUMP || last == OPTION_ID_PLAYER
				|| last == OPTION_ID_V)
			return (0);
		return (OPTION_DUMP);
	}
	else if (!ft_strcmp(arg, "-n"))
	{
		if (last == OPTION_DUMP || last == OPTION_ID_PLAYER
				|| last == OPTION_ID_V)
			return (0);
		return (OPTION_ID_PLAYER);
	}
	else if (!ft_strcmp(arg, "-v"))
	{
		if (last == OPTION_DUMP || last == OPTION_ID_PLAYER
				|| last == OPTION_ID_V)
			return (0);
		return (OPTION_VERBOSE);
	}
	else
		return (parse_one_arg_value(last, arg, value));
}

t_vm			parse_arg(int argc, char **argv)
{
	int		i;
	int		last_command;
	char	*value;
	t_vm	vm;

	i = 1;
	last_command = 0;
	value = NULL;
	vm = init_vm();
	while (i < argc)
	{
		last_command = parse_one_arg(last_command, argv[i], &value);
		if (!last_command)
			error_parsing("Command error");
		else if (last_command == OPTION_DUMP_V)
			vm.max_cycle = ft_atoi(value);
		else if (last_command == OPTION_ID_V)
			add_player(&(vm.list_players), ft_atoi(value));
		else if (last_command == OPTION_FILE_PLAYER)
			add_player_file(&(vm.list_players), value);
		else if (last_command == OPTION_VERB_V)
			set_verbose(&vm, ft_atoi(value));
		i++;
	}
	return (vm);
}

int				magic_valid(unsigned char magic[4])
{
	return (magic[0] == 0 &&
			magic[1] == 234 &&
			magic[2] == 131 &&
			magic[3] == 243);
}
