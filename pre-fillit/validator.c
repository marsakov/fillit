/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:00:19 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/31 13:41:24 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

//static int	ft_checkfigure(char *fgr)
//{
//int 
//	return (1);
//}

static int	ft_checksize(char *fgr)
{
	printf("im here and the figure is\n---\n%s\n---\n", fgr);
	int i;
	int dot;
	int hash;

	i = 0;
	dot = 0;
	hash = 0;
	while (i < 21)
	{
		if (i % 5 == 4 && fgr[i] != '\n')
			return (0);
		if (fgr[i] == '.')
			dot++;
		else if (fgr[i] == '#')
			hash++;
		i++;
	}
	printf("%d %d\n", dot, hash);
	if (dot != 12 || hash != 4)
		return (0);
//	if (!ft_checkfigure(fgr))
//		return (0);
	return (1);
}

int		ft_validate(t_piece *lst)
{
	while (lst)
	{
		printf("im in while\n");
		if (!ft_checksize(lst->figure))
			return (0);
		lst = lst->next;
	}
	return (1);
}
