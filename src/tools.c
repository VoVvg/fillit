/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:10:44 by bstacksp          #+#    #+#             */
/*   Updated: 2019/11/26 20:40:42 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	flistdel(t_tlist *list)
{
	t_tlist *fre;

	while (list)
	{
		fre = list;
		list = list->next;
		free(fre);
	}
}

void	clearmass(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		ft_strdel(&res[i]);
		i++;
	}
}

int		ft_check_open_file(int fd, int ac, char **av)
{
	int count;

	count = 0;
	if (ac != 2)
	{
		write(1, "usage: fillit input_file\n", 26);
		return (0);
	}
	if (!(fd = open(av[1], O_RDONLY)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (fd);
}

int		ft_check_count(int count)
{
	if (count == -1)
	{
		write(1, "error\n", 6);
		return (-1);
	}
	return (1);
}
