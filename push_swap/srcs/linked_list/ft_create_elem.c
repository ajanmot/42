/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:56:50 by ajanmot           #+#    #+#             */
/*   Updated: 2017/12/01 22:56:52 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/include.h"

t_pile	*ft_create_elem(int value)
{
	t_pile *element;

	element = (t_pile*)malloc(sizeof(*element));
	if (element == NULL)
		return (0);
	element->value = value;
	element->next = NULL;
	return (element);
}
