/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:33:59 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/12 17:31:23 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *dest;

	dest = (char*)malloc(sizeof(*dest) * ft_strlen(src) + 1);
	if (!dest)
		return (0);
	dest = ft_strncpy(dest, src, (unsigned int)ft_strlen(src) + 1);
	return (dest);
}
