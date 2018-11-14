# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 04:03:00 by pgerbaud          #+#    #+#              #
#    Updated: 2018/03/31 04:19:37 by pgerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all : vm asm

vm :
	@make -C vm

asm :
	@make -C asm

clean_asm :
	@make -C asm clean

clean_vm :
	@make -C vm clean

clean : clean_asm clean_vm

fclean : clean
	@make -C asm fclean
	@make -C vm fclean

re : fclean all

.PHONY : all clean clean_asm clean_vm fclean re vm asm
