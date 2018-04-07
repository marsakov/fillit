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

static int ft_find_place(char **map, t_piece *lst, int *indexes, int n);

static int ft_fill_map(char **map, t_map **solutions, int *indexes)
{
	
//	try to fill map
//		didn't fill - return (0);
//	if didnt't return 0:
// 	add map to solutions
// 	return 1
}

void	ft_reshator(t_piece *lst)
{
	int n = 2;
	char **map = ft_create_map(n);
	t_map *solutions; //remember filled maps
	int *indexes;

	malloc indexes[2];
	while (lst->next)
	{
		if (indexes[0] == n || indexes[1] == n || !(ft_find_place(map, lst, indexes, n)))
		{
			map = ft_create_map(++n);
			ft_rewrite_map(solutions, map);
			indexes[0] = 0;
			indexes[1] = 0;
		}
		else
		{
			if (ft_fill_map(map, &solutions, indexes)
			{
				indexes[0] = 0;
				indexes[1] = 0;
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