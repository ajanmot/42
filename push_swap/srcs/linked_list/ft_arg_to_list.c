/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:53:01 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/13 08:00:25 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	ft_del(t_pile **head)
{
	t_pile *current;
	t_pile *tmp;

	current = *head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		tmp = NULL;
	}
	*head = NULL;
}

int		ft_free_tab(char **tab, int status)
{
	char	*tmp;
	char	**head;

	head = tab;
	while (*tab)
	{
		tmp = *tab;
		tab++;
		free(tmp);
	}
	free(head);
	return (status);
}

int		arg_to_list(int argc, char **argv, t_pile **a)
{
	int		i;
	char	**tab;
	char	**tmp;

	i = 1;
	if (argc < 2)
		exit(1);
	while (i < argc)
	{
		tab = ft_strsplit(argv[i], ' ');
		tmp = tab;
		if (ft_is_valid(tmp) == -1)
			return (ft_free_tab(tmp, 0));
		ft_list_push_params(a, tmp);
		i++;
		ft_free_tab(tab, 0);
	}
	if (!ft_check_doublons(*a))
		return (0);
	return (1);
}
