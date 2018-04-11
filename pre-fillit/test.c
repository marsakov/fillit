/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:35:28 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/04/10 14:35:33 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	ft_swap_list(t_piece *lst)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	int a = 0;
	t_piece *temp;
	temp = lst;
	while(temp)
	{
		temp = temp->next;
		a++;
	}
	printf("%d\n", a);

}