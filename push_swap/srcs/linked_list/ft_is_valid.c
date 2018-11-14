/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:55:18 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/12 15:31:14 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	ft_check_max(char *str, char *comp)
{
	int len;

	comp = ft_strcpy(comp, "2147483647");
	len = ft_strlen(str);
	if (len > 10)
		return (-1);
	if (len < 10)
		return (1);
	while (*str && *comp && ft_isdigit(*str) && *str <= *comp)
	{
		str++;
		comp++;
	}
	if (!*str && !*comp)
		return (1);
	else if ((*str > *comp) || !ft_isdigit(*str))
		return (-1);
	else
		return (1);
}

int	ft_check_min(char *str, char *comp)
{
	int len;

	len = ft_strlen(str);
	comp = ft_strcpy(comp, "2147483648");
	if (len > 10)
		return (-1);
	if (len < 10)
		return (1);
	while (*str && *comp && ft_isdigit(*str) && *str <= *comp)
	{
		str++;
		comp++;
	}
	if (!*str && !*comp)
		return (1);
	else if ((*str > *comp) || !ft_isdigit(*str))
		return (-1);
	else
		return (1);
}

int	ft_check_range(char *str)
{
	char	*comp;
	int		result;

	if (!(comp = (char *)malloc(sizeof(char) * 11)))
		return (-1);
	if (*str == '-')
	{
		str++;
		result = ft_check_min(str, comp);
		free(comp);
		return (result);
	}
	else if (*str == '+' || ft_isdigit(*str))
	{
		if (*str == '+')
			str++;
		result = ft_check_max(str, comp);
		free(comp);
		return (result);
	}
	else
	{
		free(comp);
		return (-1);
	}
}

int	ft_check_doublons(t_pile *a)
{
	t_pile *tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				return (0);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}

int	ft_is_valid(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_check_range(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}
