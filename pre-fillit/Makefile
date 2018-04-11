#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 11:22:47 by yzavhoro          #+#    #+#              #
#    Updated: 2018/04/10 11:44:46 by yzavhoro         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Wall -Wextra -Werror
SRCS = main.c validator.c reshatorTOPCHICK.c fillit.c
LIB = libft.a
EXEC = fillit
HDR = fillit.h

all:
	@ gcc $(FLAGS) $(SRCS) $(LIB) -I $(HDR) -o $(EXEC)

clean:
	@ rm -f *~

fclean: clean
	@ rm -f $(NAME)

re: fclean all