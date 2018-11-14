/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoblech <hsoblech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 04:34:57 by hsoblech          #+#    #+#             */
/*   Updated: 2018/03/30 21:52:49 by hsoblech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	(*g_get_op_function(unsigned char id))(t_vm*, t_process*)
{
	void (*op_function[16])(t_vm*, t_process*);

	op_function[0] = op_alive;
	op_function[1] = op_load;
	op_function[2] = op_store;
	op_function[3] = op_addition;
	op_function[4] = op_substraction;
	op_function[5] = op_and;
	op_function[6] = op_or;
	op_function[7] = op_xor;
	op_function[8] = op_jump;
	op_function[9] = op_load_index;
	op_function[10] = op_store_index;
	op_function[11] = op_fork;
	op_function[12] = op_long_load;
	op_function[13] = op_long_load_index;
	op_function[14] = op_long_fork;
	op_function[15] = op_aff;
	return (op_function[id - 1]);
}
