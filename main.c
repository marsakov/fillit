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

	if (buff[4] != '\n' || buff[9] != '\n' || buff[14] != '\n'
		|| buff[19] != '\n' || (buff[20] && buff[20] != '\n'))
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

static char		**ft_create_map(int n)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	while (i < n)
		if (!(map[i++] = (char*)malloc(sizeof(char) * (n + 1))))
			return (NULL);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
			map[i][j++] = '.';
		map[i++][j] = '\0';
	}
	map[i] = NULL;
	return (map);
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

static void		ft_masha(t_piece *lst, int *ts)
{
	char	**map;
	int		n;

	if (ts[1] != 20 || !ft_validate(lst))
	{
		ft_putendl("error");
		return ;
	}
	n = 2;
	map = ft_create_map(n);
	while (!ft_fillit(lst, map, n))
		map = ft_create_map(++n);
	print_map(map);
}

int				main(int ac, char **av)
{
	int		fd;
	char	buff[22];
	t_piece	*lst;
	char	ltr;
	int		ts[2];

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			return (0);
		ft_bzero(buff, 22);
		ltr = 'A';
		lst = NULL;
		while ((ts[0] = read(fd, buff, 21)))
		{
			ts[1] = ts[0];
			ft_fill_elem(&lst, buff, ltr++);
			ft_bzero(buff, 22);
		}
		close(fd);
		ft_masha(lst, ts);
	}
	else
		ft_putendl("usage: fillit [file]");
	return (0);
}
