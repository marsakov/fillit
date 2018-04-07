/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psevdokod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 11:38:29 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/04/07 11:38:32 by yzavhoro         ###   ########.fr       */
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

static void	ft_rewrite_map(t_map *solutions, char **map)
{	
	int i;
	int j;

	while (solutions->next)
		solutions = solutions->next;
	i = 0;
	while (solutions->map[i])
	{
		j = 0;
		while (solutions->map[i][j])
		{
			map[i][j] = solutions->map[i][j];
			j++;
		}
		i++;
	}
}

static int ft_find_place(char **map, int *indexes, int n)
{
	print_map(map);
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

static int ft_fill_map(char ***map, t_map **solutions, int *indexes, int n, t_piece *lst)
{
	
//	try to fill map
//		didn't fill - return (0);
//	if didnt't return 0:
// 	add map to solutions
// 	return 1

	int x;
	int y;
	int i;
	int j;
	t_map *tmp;
	char **copy;


	copy = ft_copy_map(*map);
	printf("+++++++++++++++++++++++++++++++++++++\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~EN: %d\n", n);
	print_map(copy);
	printf("+++++++++++++++++++++++++++++++++++++\n");
	i = indexes[0];
	j = indexes[1];
	
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
				if (lst->figure[y][x] == '#' && i + y - lst->y_start < n && j + x - lst->x_start < n)
				{
					if ((*map)[i + y - lst->y_start][j + x - lst->x_start] == '.')
					{
						if (lst->letter == 'D')
							printf("%d %d : %d %d - %d\n", y, x, i + y - lst->y_start, j + x - lst->x_start, n);
						(*map)[i + y - lst->y_start][j + x - lst->x_start] = lst->letter;
					}
				}
				else if (lst->figure[y][x] == '#')
				{
					*map = copy;
					printf("^^^^^^^^^^^^^^copy:\n");	
					print_map(*map);
					printf("^^^^^^^^^^^^^^\n");
					return (0);
				}
			x++;
		}
		y++;
	}
	printf("                                                                          ne vernul 0\n");
	tmp = *solutions;
	if (!tmp)
	{
		if (!(*solutions = (t_map*)malloc(sizeof(t_map))))
			return (0);
		(*solutions)->map = *map;
		(*solutions)->size = n;
		(*solutions)->next = NULL;
		*map = copy;
		printf("HHHHHHHHHHHHHHH\n");
		print_map((*solutions)->map);
		printf("HHHHHHHHHHHHHHH\n");
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_map*)malloc(sizeof(t_map))))
			return (0);
		tmp->next->map = *map;
		tmp->next->size = n;
		tmp->next->next = NULL;
		//*map = copy;
		printf("HhHHHHHHHHHHHHH\n");
		print_map(tmp->map);
		printf("HHHHHHHHHHHHHHH\n");
	}
	return (1);

	// t_piece *tmp;

	// tmp = *lst;
	// if (*lst)
	// {
	// 	while (tmp->next)
	// 		tmp = tmp->next;
	// 	tmp->next = ft_addblock(buff, ltr);
	// }
	// else
	// 	*lst = ft_addblock(buff, ltr);
}

void	ft_reshator(t_piece *lst)
{
	int n = 2;
	char **map = ft_create_map(n);
	t_map *solutions; //remember filled maps
	int *indexes;

	if (!(indexes = (int*)malloc(sizeof(int) * 2)))
		return ;
	indexes[0] = 0;
	indexes[1] = 0;
	solutions = NULL;
	while (lst)
	{
		print_map(map);
		if ((indexes[0] == n || indexes[1] == n) || !(ft_find_place(map, indexes, n)))
		{
			printf("im updating map\n");
			map = ft_create_map(++n);
			if (solutions)
			{
				ft_rewrite_map(solutions, map);
			}
			indexes[0] = 0;
			indexes[1] = 0;
		}
		else
		{
			if (ft_fill_map(&map, &solutions, indexes, n, lst))
			{
				indexes[0] = 0;
				indexes[1] = 0;
				printf("                                                 next\n");
				lst = lst->next;
			}
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
	}
}