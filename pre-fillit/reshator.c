/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reshator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:21:14 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/04/04 15:21:18 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	print_map(char **map)
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
	printf("end of map\n\n");
}

static int		ft_fill_map(char **map, t_piece *lst, int i, int j)
{
	int x;
	int y;
	int counter;
	char **temp;

	y = 0;
	counter = 0;
	temp = map;
	print_map(map);
	while(y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (counter < 5 && lst->figure[y][x] == '#' && map[i + y - lst->y_start]
				&& map[i + y - lst->y_start][j + x - lst->x_start] == '.')
			{
				map[i + y - lst->y_start][j + x - lst->x_start] = lst->letter;
				counter++;
			}
			else if ((counter < 5 && lst->figure[y][x] == '#' && map[i + y - lst->y_start]
				&& map[i + y - lst->y_start][j + x - lst->x_start] != '.'))//|| !map[i + y - lst->y_start])
			{
				print_map(map);
				printf("no try next line\n");
				//print map
				map = temp;
				y = 0;
				x = -1;
				i++;
				printf("Press enter to continue...\n");
				getchar();
				//return (0);
				break ;
			}
			else if (counter < 5 && !map[i + y - lst->y_start])
			{
				print_map(map);
				printf("n++\n");
				printf("Press enter to continue...\n");
				getchar();
				return (0);
			}
			else if (counter == 4)
			{
				printf("i returned 1\n");
				return (1);
			}
			x++;
		}
		y++;
	}
	printf("i returned 1\n");
	return (1);
}

static t_map	*ft_mapbuff(char **map, int n)
{
	t_map *elem;
	int i;
	
	i = 0;
	
	if (!(elem = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(elem->map = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	while(i < n)
	{
		if (!(elem->map[i] = (char*)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		if (map[i])
			ft_strcpy(elem->map[i], map[i]);
		
		i++;
	}
	elem->map[i] = NULL;
	elem->size = n;
	return (elem);
}

static int		ft_find_place(char **map, t_piece *lst, t_map **solutions, int n)
{
	int i;
	int j;
	t_map *temp;

	i = -1;
	temp = *solutions;
	while (map[++i])
	{
		j = -1;
		while(map[i][++j])
			if (map[i][j] == '.')
			{
				if (!(ft_fill_map(map, lst, i, j)))
				{
					printf("i didnt fill the map\n");
					return (0);
				}
				else
				{
					printf("i filled the map\n");
					if (temp)
					{
						while (temp->next)
							temp = temp->next;
						temp->next = ft_mapbuff(map, n);
					}
					else
						*solutions = ft_mapbuff(map, n);
					printf("and im gonne return 1\n");
					return (1);
				}
			}
	}
	return (1);
}

static char		**ft_create_map(int n)
{
	int i;
	int j;
	char **map;
	
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

void			ft_reshator(t_piece *lst)
{
	int n;
	char **map;
	t_map *solutions;
	t_piece *begin;

	n = 2;
	begin = lst;
	solutions = NULL;
	map = ft_create_map(n);
	while (lst)
	{
		if (!(ft_find_place(map, lst, &solutions, n)))
		{
			lst = begin;
			map = ft_create_map(++n);
		}
		else
		{
			lst = lst->next;
			printf("i moved to next lst\n");
		}
	}
	while (solutions->next)
		solutions = solutions->next;
	for(int i = 0; solutions->map[i]; i++)
		printf("%sLL\n", solutions->map[i]);
}
















