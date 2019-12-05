/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_tetrimino.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 18:03:12 by sroland           #+#    #+#             */
/*   Updated: 2019/12/01 19:29:14 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_symbols(char *tetr)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (++i <= 19)
	{
		if (((i + 1) % 5) == 0)
		{
			if (tetr[i] != '\n')
				return (0);
		}
		else if ((tetr[i] != '.') && (tetr[i] != '#'))
			return (0);
		if (tetr[i] == '#')
			count++;
		if (count > 4)
			return (0);
	}
	if (count < 4)
		return (0);
	return (1);
}

int			init_int(int *a, int *b, int *c, int *d)
{
	*a = 5;
	*b = 0;
	*c = 5;
	*d = 0;
	return (0);
}

int			is_valid_tetr(char *tetr, t_t_list *t_l)
{
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
	int		i;

	i = -1;
	init_int(&x_min, &x_max, &y_min, &y_max);
	while (++i < 20)
		if (tetr[i] == '#')
		{
			x_min = ((i + 1) % 5 < x_min ? (i + 1) % 5 : x_min);
			x_max = ((i + 1) % 5 > x_max ? (i + 1) % 5 : x_max);
			y_min = ((i + 1) / 5 < y_min ? (i + 1) / 5 : y_min);
			y_max = ((i + 1) / 5 > y_max ? (i + 1) / 5 : y_max);
		}
	if (x_max - x_min + y_max - y_min > 3)
		return (0);
	t_l->x_m = x_min - 1;
	t_l->y_m = y_min;
	t_l->x = x_max - x_min + 1;
	t_l->y = y_max - y_min + 1;
	return (1);
}

int			write_tetr(char *tetr, t_t_list *t_l)
{
	int			i;
	int			j;

	i = t_l->x_m;
	while (i < t_l->x_m + t_l->x)
	{
		j = t_l->y_m;
		while (j < t_l->y_m + t_l->y)
		{
			t_l->tetr[i - t_l->x_m][j - t_l->y_m] = tetr[j * 5 + i];
			j++;
		}
		i++;
	}
	if ((t_l->x == 3 && t_l->tetr[1][0] == '.' && t_l->tetr[1][1] == '.')
	|| (t_l->y == 3 && t_l->tetr[0][1] == '.' && t_l->tetr[1][1] == '.'))
		return (0);
	return (1);
}
