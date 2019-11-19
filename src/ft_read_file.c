/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:54:24 by bstacksp          #+#    #+#             */
/*   Updated: 2019/11/19 16:59:08 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_flist		*ft_read_file(int fd)
{
	t_flist	*file;
	t_flist	*head;
	char	buf[22];
	int		flag;

	file = malloc(sizeof(t_flist));
	head = file;
	flag = 0;
	while (read(fd, buf, 21) > 0)
	{
		buf[20] = '\0';
		file->next = malloc(sizeof(t_flist));
		file->tmp = ft_strdup(buf);
		file = file->next;
		// if (ft_valide(file->tmp) > 0)
		// 	return NULL;
		read(fd, buf, 1);
	}
	free(file->next);
	file->next = NULL;
	return (head);
}
