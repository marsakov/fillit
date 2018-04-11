/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:35:42 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/04/10 19:35:43 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int	ft_fillit(t_piece *lst, char **map, int n)
{
	int *indexes;
	char **copy;

	if (!lst)
		return (1);
	copy = ft_copy_map(map);
	indexes = (int*)malloc(sizeof(int) * 2);
	indexes[0] = 0;
	indexes[1] = 0;
	while (indexes[0] < n)
	{
		while (indexes[1] < n)
		{
			if (ft_reshator(lst, map, n, indexes))
			{
				if (ft_fillit(lst->next, map, n))
					return (1);
				else
					ft_rewrite_map(copy, map, n);
			}
			indexes[1]++;
		}
		indexes[0]++;
	}
	return (0);
}