/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:21:30 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/30 20:21:43 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_calloc(size_t size)
{
	void	*final;

	if (size == 0)
		return (0);
	if (!(final = (void *)malloc(size)))
		return (0);
	ft_bzero(final, size);
	return (final);
}
