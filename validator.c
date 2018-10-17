/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:00:19 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/04/04 12:14:05 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

static int	ft_add_coords(t_piece *lst)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (lst->figure[i][j] == '#')
			{
				lst->x_start = j;
				lst->y_start = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_checkfigure(t_piece *lst, int i, int j)
{
	int count;

	count = 0;
	if (i && lst->figure[i - 1][j] == '#')
		count++;
	if (i < 3 && lst->figure[i + 1][j] == '#')
		count++;
	if (j && lst->figure[i][j - 1] == '#')
		count++;
	if (j < 3 && lst->figure[i][j + 1] == '#')
		count++;
	return (count);
}

static int	ft_checksize(t_piece *lst)
{
	int i;
	int j;
	int dot;
	int hash;
	int connect;

	i = -1;
	dot = 0;
	hash = 0;
	connect = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (lst->figure[i][j] == '.')
				dot++;
			else if (lst->figure[i][j] == '#')
			{
				hash++;
				connect += ft_checkfigure(lst, i, j);
			}
	}
	if (dot != 12 || hash != 4 || (connect != 6 && connect != 8))
		return (0);
	return (1);
}

int			ft_validate(t_piece *lst)
{
	int s;

	s = 0;
	while (lst)
	{
		if (!ft_checksize(lst))
			return (0);
		ft_add_coords(lst);
		s++;
		lst = lst->next;
	}
	if (s > 26)
		return (0);
	return (s);
}
