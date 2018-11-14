/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_to_func_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:56:04 by ajanmot           #+#    #+#             */
/*   Updated: 2017/11/30 18:56:05 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void			setup_arr(t_ptr_func *func_tab)
{
	func_tab['%'] = &ft_handle_escape;
	func_tab['s'] = &ft_handle_str;
	func_tab['S'] = &ft_handle_wstr;
	func_tab['p'] = &ft_handle_ptr;
	func_tab['d'] = &ft_handle_int;
	func_tab['D'] = &ft_handle_long;
	func_tab['i'] = &ft_handle_int;
	func_tab['o'] = &ft_handle_octal;
	func_tab['O'] = &ft_handle_long;
	func_tab['u'] = &ft_handle_unsigned;
	func_tab['U'] = &ft_handle_long;
	func_tab['x'] = &ft_handle_hex;
	func_tab['X'] = &ft_handle_hex;
	func_tab['c'] = &ft_handle_char;
	func_tab['C'] = &ft_handle_wchar;
	func_tab['b'] = &ft_handle_binary;
}

t_ptr_func		g_ft_get_func(char c)
{
	t_ptr_func *func_tab;
	t_ptr_func func_type;

	func_tab = ft_memalloc(sizeof(*func_tab) * 256);
	if (func_tab)
		setup_arr(func_tab);
	func_type = func_tab[(int)c];
	free(func_tab);
	return (func_type);
}
