/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajanmot <ajanmot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:48:05 by ajanmot           #+#    #+#             */
/*   Updated: 2018/02/25 18:18:24 by ajanmot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define X '\n'
# define SS stock[fd]
# define BUFF_SIZE 1
# define OPEN_MAX 256

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int		get_next_line(int const fd, char **line, int status);

#endif
