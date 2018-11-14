/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:16:36 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/11 21:09:24 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *current;

	if (!lst || !f)
		return (NULL);
	result = (*f)(lst);
	current = result;
	while (lst->next)
	{
		current->next = (*f)(lst->next);
		current = current->next;
		lst = lst->next;
	}
	return (result);
}
