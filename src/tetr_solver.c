/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 22:41:42 by sroland           #+#    #+#             */
/*   Updated: 2019/11/26 20:40:37 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		insert(char **field, int x, int y, t_tlist *t_l)
{
	int			i;
	int			j;

	i = x;
	while (i < x + t_l->x)
	{
		j = y;
		while (j < y + t_l->y)
		{
			if (t_l->tetr[i - x][j - y] == '#')
			{
				if (field[x][y] < t_l->letter)
					return (-1);
				else
					field[x][y] = t_l->letter;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		solver(int size, char **field, t_tlist *t_l)
{
	int			i;
	int			j;

	if (t_l == NULL)
		return (1);
	j = 0;
	while (j < size - t_l->y)
	{
		i = 0;
		while (i < size - t_l->x)
		{
			if ((insert(field, i, j, t_l) == 1) &&
				solver(size, field, t_l->next) == 1)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

char	**field_init(int size)
{
	int			i;
	int			j;
	char		**res;

	res = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		res[i] = (char *)malloc(sizeof(char) * 25);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			res[i][j] = 'a';
			j++;
		}
		i++;
	}
	return (res);
}

int		print_field(char **field, int size)
{
	int			i;
	int			j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (field[i][j] == 'a')
				write(1, ".", 1);
			else
				write(1, &field[i][j], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
	return (0);
}
