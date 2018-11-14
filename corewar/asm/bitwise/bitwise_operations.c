/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:21:39 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/30 17:30:34 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

unsigned char		binary_to_byte(char *string)
{
	int				counter;
	unsigned char	byte;

	byte = 0;
	counter = 0;
	while (*string)
	{
		if (*string == '1')
			byte |= 1UL << counter;
		counter++;
		string++;
	}
	return (byte);
}

const char			*byte_to_binary(int x)
{
	static char		b[9];
	int				z;

	b[0] = '\0';
	z = 128;
	while (z > 0)
	{
		ft_strcat(b, ((x & z) == z) ? "1" : "0");
		z >>= 1;
	}
	return (b);
}

unsigned int		rev_indian(unsigned int n)
{
	unsigned int	rev;

	rev = 0;
	rev += (n & 0xFF);
	rev <<= 8;
	rev += (n & 0xFF00) >> 8;
	rev <<= 8;
	rev += (n & 0xFF0000) >> 16;
	rev <<= 8;
	rev += (n & 0xFF000000) >> 24;
	return (rev);
}

unsigned char		*int_to_bytes(t_file *file, long n, int nb_bytes)
{
	unsigned char	*byte_array;

	if (!(byte_array = (unsigned char *)ft_calloc(sizeof(unsigned char) *
nb_bytes + 1)))
		ft_error_asm("Error ft_calloc", file, 0);
	byte_array[0] = (int)((n & 0X000000FF));
	if (nb_bytes == 2)
	{
		byte_array[0] = (int)((n & 0x0000FF00) >> 8);
		byte_array[1] = (int)((n & 0X000000FF));
	}
	if (nb_bytes == 3)
	{
		byte_array[0] = (int)((n & 0x00FF0000) >> 16);
		byte_array[1] = (int)((n & 0x0000FF00) >> 8);
		byte_array[2] = (int)((n & 0X000000FF));
	}
	if (nb_bytes == 4)
	{
		byte_array[0] = (int)((n & 0xFF000000) >> 24);
		byte_array[1] = (int)((n & 0x00FF0000) >> 16);
		byte_array[2] = (int)((n & 0x0000FF00) >> 8);
		byte_array[3] = (int)((n & 0X000000FF));
	}
	return (byte_array);
}

unsigned char		reverse_bits(unsigned char b)
{
	unsigned char	r;
	unsigned		byte_len;

	r = 0;
	byte_len = 8;
	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}
