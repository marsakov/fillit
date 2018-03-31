/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:26:40 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/03/31 13:49:50 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_piece
{
	char			figure[21];
	struct s_piece	*next;
	char			letter;
}					t_piece;

int     			ft_validate(t_piece *begin);

#endif
