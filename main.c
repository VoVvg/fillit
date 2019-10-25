/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:51:45 by bstacksp          #+#    #+#             */
/*   Updated: 2019/10/25 22:54:41 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

int		ft_valid(char *s)
{
	char	str[547];
	int		i;
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		write(1, "error\n", 6);
		exit(0);
	}
	i = read(fd, str, 548);
	if (!((i + 2) % 21))
	{
		close(fd);
		write(1, "error\n", 6);
		exit(0);
	}
	close(fd);
	return (0);
}

int		ft_validn(char *sss)
{
	int		i;
	char	str[547];
	int		fd;

	fd = open(sss, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		write(1, "error\n", 6);
		exit(0);
	}
	i = read(fd, str, 548);
	if (!((i + 2) % 21))
	{
		close(fd);
		write(1, "error\n", 6);
		exit(0);
	}
	close(fd);
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		**map;
	t_flist		*list;

	if (argc != 2)
	{
		write(1, "usage: fillit input_file\n", 26);
		return (0);
	}
	fd = open(argv[1] + ft_validn(argv[1]), O_RDONLY);
	if (!(list = read_grid(fd)))
	{
		write(1, "error\n", 6);
		return (0);
	}
}
