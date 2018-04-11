/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reshatorTOPCHICK.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:35:05 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/04/10 14:35:09 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void    print_map(char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            printf("%c", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

void ft_rewrite_map(char **src, char **map, int n)
{   
    int i;
    int j;

    i = 0;
    while (src[i] && i < n)
    {
        j = 0;
        while (src[i][j] && i < n)
        {
            map[i][j] = src[i][j];
            j++;
        }
        i++;
    }
}

static int ft_find_place(char **map, int *indexes, int n)
{
    while (indexes[0] < n)
    {
        while (indexes[1] < n)
        {
            if (map[indexes[0]][indexes[1]] == '.')
            {
                return (1);
            }
            indexes[1]++;
        }
        indexes[1] = 0;
        indexes[0]++;
    }
    return (0);
}

char	**ft_copy_map(char **map)
{
	int n;
	int i;
	char **temp;

	i = 0;
	n = 0;
	while (map[n])
		n++;
	if (!(temp = (char**)malloc(sizeof(char*) * (n + 1))))
		return (0);
	while (i < n)
	{
		if (!(temp[i] = (char*)malloc(sizeof(char) * (n + 1))))
			return (0);
		ft_strcpy(temp[i], map[i]);
		i++;
	}
	return (temp);
}

static int ft_fill_map(char **map, int *indexes, t_piece *lst, int n)
{
	int		x;
	int		y;
	int		counter;
	char	**copy;

	y = -1;
	counter = 0;
	copy = ft_copy_map(map);
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (lst->figure[y][x] == '#')
				if (I < n && J < n && map[I][J] == '.')
				{
					map[I][J] = lst->letter;
					counter++;
				}
	}
	if (counter == 4)
		return (1);
	ft_rewrite_map(copy, map, n);
    return (0);
}

int    ft_reshator(t_piece *lst, char **map, int n, int *indexes)
{
    char    **copy;

    copy = ft_copy_map(map);
    while (indexes[0] < n && indexes[1] < n && ft_find_place(map, indexes, n))
    {
        if (ft_fill_map(map, indexes, lst, n))
            return (1);
        else
        {
            if (indexes[1] < n - 1)
                indexes[1]++;
            else
            {
                indexes[0]++;
                indexes[1] = 0;
            }
        }
    }
    ft_rewrite_map(copy, map, n);
    return (0);
}
