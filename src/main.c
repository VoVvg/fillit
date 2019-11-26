/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:04:52 by bstacksp          #+#    #+#             */
/*   Updated: 2019/11/26 20:39:23 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int				fd;
	int				count;
	int				size;
	t_tlist			*t_l;
	char			**field;

	fd = 0;
	if (!(fd = ft_check_open_file(fd, ac, av)))
		return (0);
	t_l = (t_tlist *)malloc(sizeof(t_tlist));
	count = read_tetr(fd, t_l);
	if (!ft_check_count(count))
		return (0);
	size = 0;
	while (size * size < count * 4)
		size++;
	field = field_init(25);
	while (solver(size, field, t_l) == 0)
		size++;
	print_field(field, size);
	clearmass(field);
	free(field);
	flistdel(t_l);
	return (0);
}
