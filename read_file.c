/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:54:24 by bstacksp          #+#    #+#             */
/*   Updated: 2019/10/29 14:46:14 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_flist		*read_file(int fd)
{
	t_flist		*file;
	t_flist		*head;
	int			buf[22];

	while (read(fd, buf, 21) > 0)
	{
		buf[22] = '\0';
		file = malloc(sizeof(t_flist));
		file->next = NULL;
		file->temp = ft_strdup(buf);
		CHECKRETURN(!(valide(file->temp)), NULL);
		read(fd, buf, 1);
		if (buf[0] != '\n')
			file = file->next;
	}
}
