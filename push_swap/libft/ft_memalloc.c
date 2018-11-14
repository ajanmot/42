/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:19:49 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/11 20:19:57 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *new;

	new = NULL;
	if (!size)
		return ((void *)new);
	new = (void *)malloc(sizeof(void) * size);
	if (new)
	{
		ft_bzero(new, size);
		return (new);
	}
	else
		return (NULL);
}
