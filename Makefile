#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 21:21:48 by msakovyc          #+#    #+#              #
#    Updated: 2018/04/11 21:21:52 by msakovyc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
HDR  = libft
SRCS = reshator.c	\
	   validator.c	\
	   main.c		\
	   fillit.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ make -C libft re
	@ gcc $(FLAGS) -o $(NAME) -I $(HDR) -L ./libft/ -lft $(OBJ)

%.o:%.c
	@ gcc -o $@ -c $< -I ./libft/

clean:
	@ rm -f $(OBJ)
	@ make -C libft clean

fclean: clean
	@ rm -f $(NAME)
	@ make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
