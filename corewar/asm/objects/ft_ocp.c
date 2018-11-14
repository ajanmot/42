/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ocp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:23:25 by tkeynes           #+#    #+#             */
/*   Updated: 2018/03/30 18:31:12 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

unsigned char	generate_ocp(t_file *file, t_instruction *instruction,
int counter)
{
	t_operande		**operandes;
	char			*ocp;
	unsigned char	final;

	operandes = instruction->args;
	if (!(ocp = (char *)ft_calloc(sizeof(char) * 9)))
		ft_error_asm("error ft_calloc", file, 0);
	ft_bzero(ocp, sizeof(char) * 9);
	while (*operandes)
	{
		if (*(*operandes)->initial == '%')
			ft_strcat(ocp, "10");
		else if ((*operandes)->type == T_REG)
			ft_strcat(ocp, "01");
		else
			ft_strcat(ocp, "11");
		operandes++;
		counter++;
	}
	while (counter++ != 4)
		ft_strcat(ocp, "00");
	final = binary_to_byte(ocp);
	ft_free(ocp);
	return (final);
}
