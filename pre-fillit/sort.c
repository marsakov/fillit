/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:07:37 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/04/10 15:07:38 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	number[10];

void		ft_whatislove(int max, int index)
{
	int		exists;
	int		nbr;
	int		i;
	int		j;
	int		k;

	i = max - 1;
	while (i >= 0)
	{
		j = 1;
		while (j <= max)
		{
			k = 0;
			exists = 0;
			while (k < i)
				if (number[k++] == nbr)
					exists = 1;
			if (!exists)
			{

			}
			if (number[i] < max)
			{
				number[i]++;
				k = 0;
				while (k < 10 && number[k] != 0)
					printf("%d", number[k++]);
				printf("\n");
			}
			j++;
		}
		i--;
	}
}
/*
static int	nbr;

void		ft_whatislove(int max, int index)
{
	int		exists;
	int		nbr;
	int		i;
	int		j;

	nbr = 1;
	while (nbr <= max)
	{
		i = 0;
		exists = 0;
		while (i < index)
			if (number[i++] == nbr)
				exists = 1;
		if (exists)
			ft_whatislove(max, index + 1);
		else
			number[index] = nbr;
		j = 0;
		while (j < 10 && number[j] != 0)
			printf("%d", number[j++]);
		printf("\n");
		nbr++;
	}
}

*/
void ft_sort(int i)
{
	int a = 1, b, c, d;
	while (a <= i)
	{
		b = 1;
		while (b <= i)
		{
			c = 1;
			while (c <= i)
			{
				d = 1;
				while (d <= i)
				{
					if (a != b && b != c && c != d && a != c && a!= d && b!= d)
						printf("%d %d %d %d\n", a, b, c, d);
					d++;
				}
				c++;
			}
			b++;
		}
		a++;
	}
}

int main(int argc, char **argv)
{
	int i;
	int j;

	i = -1;
	while (++i < atoi(argv[1]))
		number[i] = i + 1;
	j = 0;
	while (j < 10 && number[j] != 0)
		printf("%d", number[j++]);
	printf("\n");
	ft_whatislove(atoi(argv[1]), 0);
	//ft_sort(4);
	return 0;
}
