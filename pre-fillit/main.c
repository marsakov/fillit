/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:22:58 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/04/03 11:56:07 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

static t_piece	*ft_addblock(char *buff, char ltr)
{
	int		i;
	int		j;
	t_piece	*new;

	if (buff[20] != '\n' || buff[4] != '\n' || buff[9] != '\n'
		|| buff[14] != '\n' || buff[19] != '\n')
	{
		ft_putendl("error");
		exit(0);
	}
	new = (t_piece*)malloc(sizeof(t_piece));
	i = 0;
	while (*buff && i < 4)
	{
		j = 0;
		while (j < 4)
			new->figure[i][j++] = *buff++;
		buff++;
		i++;
	}
	new->letter = ltr;
	new->next = NULL;
	return (new);
}

static void		ft_fill_elem(t_piece **lst, char *buff, char ltr)
{
	t_piece *tmp;

	tmp = *lst;
	if (*lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_addblock(buff, ltr);
	}
	else
		*lst = ft_addblock(buff, ltr);
}

int				main(int ac, char **av)
{
	int		fd;
	char	buff[22];
	t_piece	*lst;
	char	ltr;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			return (0);
		ft_bzero(buff, 22);
		ltr = 'A';
		lst = NULL;
		while (read(fd, buff, 21))
			ft_fill_elem(&lst, buff, ltr++);
		close(fd);
		if (!ft_validate(lst))
		{
			ft_putendl("error");
			return (0);
		}
		ft_putendl("map is OK");
	}
	else
		ft_putendl("usage: fillit [file]");
	return (0);
}
