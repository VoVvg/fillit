/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 18:05:05 by sroland           #+#    #+#             */
/*   Updated: 2019/12/01 19:29:14 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			read_tetr(int fd, t_t_list *t_l)
{
	char			a[20];
	int				count;
	t_t_list		*new;

	count = 0;
	t_l->next = NULL;
	while (read(fd, a, 20) == 20)
	{
		t_l->next = NULL;
		if (check_symbols(a) != 1 || is_valid_tetr(a, t_l) != 1)
			return (0);
		t_l->letter = 'A' + count;
		if (write_tetr(a, t_l) != 1)
			return (0);
		count++;
		if (read(fd, a, 1) == 0)
			return (count);
		else if (a[0] != '\n')
			return (0);
		if ((new = (t_t_list *)malloc(sizeof(t_t_list))) == NULL)
			return (0);
		t_l->next = new;
		t_l = t_l->next;
	}
	return (0);
}
