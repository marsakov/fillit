/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:26:40 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/04/03 11:50:09 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

# define I indexes[0] + y - lst->y_start
# define J indexes[1] + x - lst->x_start

typedef struct		s_piece
{
	char			figure[4][4];
	struct s_piece	*next;
	int				x_start;
	int				y_start;
	char			letter;
}					t_piece;

int					ft_validate(t_piece *begin);
int					ft_reshator(t_piece *lst, char **map, int n, int *indexes);
int					ft_fillit(t_piece *lst, char **map, int n);
char				**ft_copy_map(char **map);
void				ft_rewrite_map(char **src, char **map, int n);
void				print_map(char **map);

#endif
