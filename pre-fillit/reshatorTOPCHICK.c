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
    printf("end of map\n\n");
}

static char     **ft_create_map(int n)
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

static void ft_rewrite_map(char **src, char **map)
{   
    int i;
    int j;

    i = 0;
    while (src[i])
    {
        j = 0;
        while (src[i][j])
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
	int		i;
	int		j;
	int		counter;
	char	**copy;

	i = indexes[0];
	j = indexes[1];
	y = 0;
	counter = 0;
	copy = ft_copy_map(map);
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (lst->figure[y][x] == '#')
			{
				if (i + y - lst->y_start < n && j + x - lst->x_start < n && map[i + y - lst->y_start][j + x - lst->x_start] == '.')
				{
					map[i + y - lst->y_start][j + x - lst->x_start] = lst->letter;
					counter++;
				}
			}
			x++;
		}
		y++;
	}
	if (counter == 4)
		return (1);
	ft_rewrite_map(copy, map);
	return (0);
}

void    ft_reshator(t_piece *lst)
{
    int     n;
    char    **map;
    t_map   *solutions;
    t_map   *last;
    int     *indexes;

    indexes = (int *)malloc(sizeof(int) * 2);
    n = 2;
    map = ft_create_map(n);
    solutions = NULL;
    indexes[0] = 0;
    indexes[1] = 0;
    while (lst)
    {
        if (ft_find_place(map, indexes, n))
        {
            if (ft_fill_map(map, indexes, lst, n))            
            {
                indexes[0] = 0;
                indexes[1] = 0;
                if (solutions)
                {
                    last = solutions;
                    while (last->next)
                        last = last->next;
                    if (!(last->next = (t_map*)malloc(sizeof(t_map))))
                        return ;
                    last->next->map = map;
                    last->next->size = n;
                    last->next->next = NULL;
                }
                else
                {
                    if (!(solutions = (t_map*)malloc(sizeof(t_map))))
                        return ;
                    solutions->map = map;
                    solutions->size = n;
                    solutions->next = NULL;
                }
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
        else
        {
            last = solutions;
            while (last && last->next)
                last = last->next;
            map = ft_create_map(++n);
            if (last)
                ft_rewrite_map(last->map, map);
            indexes[0] = 0;
            indexes[1] = 0;
        }
    }
    printf("------------------------------------------------\n");
    while(solutions)
    {
        print_map(solutions->map);
        solutions = solutions->next;
    }
}



















