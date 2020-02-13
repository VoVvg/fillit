/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:10:05 by sroland           #+#    #+#             */
/*   Updated: 2019/12/01 19:49:07 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			clean_tetr_list(t_t_list *t_l)
{
	t_t_list		*tmp;

	while (t_l)
	{
		tmp = t_l;
		t_l = t_l->next;
		free(tmp);
	}
	return (0);
}

int			clean_field(char ***field, int size)
{
	int			i;

	i = 0;
	if (*field == NULL)
		return (0);
	while (i < size)
	{
		if ((*field)[i])
			free((*field)[i]);
		i++;
	}
	free(*field);
	return (0);
}

int			ft_sqrt(int x)
{
	int		res;

	res = 0;
	while (res * res < x)
		res++;
	return (res);
}

int			solve_tetr(int fd)
{
	t_t_list		*t_l;
	char			**field;
	int				i;

	if (!(t_l = (t_t_list *)malloc(sizeof(t_t_list))))
		return (0);
	if (!(field = field_init(25)))
		return (0);
	i = read_tetr(fd, t_l);
	if ((i == 0) || (i > 26))
	{
		clean_field(&field, 25);
		clean_tetr_list(t_l);
		return (0);
	}
	i = ft_sqrt(4 * i);
	while (solver(i, field, t_l) == 0)
		i++;
	print_field(field, i);
	clean_field(&field, 25);
	clean_tetr_list(t_l);
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		write(1, "usage: fillit input_file\n", 25);
		return (0);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (solve_tetr(fd) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (0);
}
