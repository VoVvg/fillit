/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:51:45 by bstacksp          #+#    #+#             */
/*   Updated: 2019/10/13 18:53:22 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_valid(char *s)
{
	int		i;
	int		fd;
	char    str[547];

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




int		main(int argc, char **argv)
{
	int		fd;



	if (ac != 2)
	{
		write(1, "usage: fillit input_file\n", 26);
		return (0);
	}
	fd = open(av[1] + ft_validn(av[1]), O_RDONLY);
}
