/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:43:31 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/31 14:47:40 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int		main(int ac, char **av)
{
	int fd;
	char piece[21];
	char ltr;
	t_piece *begin;
	t_piece *first;


//	begin = NULL;
	first = begin;
	ltr = 65;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			return (0);
		}
		while (read(fd, piece, 20))
		{
			if (!(begin = ft_memalloc(sizeof(t_piece))))
				return (0);
			piece[20] = '\0';
			ft_strcpy(begin->figure, piece);
			begin->letter = ltr++;
			printf("letter: %c\n%s", begin->letter, begin->figure);
			begin->next = NULL;
			begin = begin->next;
			read(fd, piece, 1);
		}
		while (first)
		{
			printf("figure:\n%s\nletter: %c\n", first->figure, first->letter);
			first = first->next;
		}
		close(fd);
		if (!ft_validate(first))
		{
			printf("invalid map\n");
			return (0);
		}
//		ft_solve(begin);
		printf("correct map\n");
	}
	else
		ft_putendl("usage: fillit [filename]");
	return (0);
}
