/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 18:05:05 by sroland           #+#    #+#             */
/*   Updated: 2019/11/26 20:39:21 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			read_tetr(int fd, t_tlist *t_l)
{
	char		a[20];
	int			count;
	t_tlist		*new;

	count = 0;
	while (read(fd, a, 20) == 20)
	{
		if (check_symbols(a) != 1 || is_valid_tetr(a, t_l) != 1)
			return (-1);
		t_l->letter = 'A' + count;
		write_tetr(a, t_l);
		count++;
		t_l->next = NULL;
		if (read(fd, a, 1) == 0)
			return (count);
		else if (a[0] != '\n')
			return (-1);
		if ((new = (t_tlist *)malloc(sizeof(t_tlist))) == NULL)
			return (-1);
		t_l->next = new;
		t_l = t_l->next;
	}
	return (-1);
}
