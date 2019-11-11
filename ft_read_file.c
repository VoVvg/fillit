/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:54:24 by bstacksp          #+#    #+#             */
/*   Updated: 2019/11/06 16:08:28 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_flist		*ft_read_file(int fd)
{
	t_flist		*file;
	t_flist		*head;
	char		buf[22];

	while (read(fd, buf, 21) > 0)
	{
		buf[21] = '\0';
		file = malloc(sizeof(t_flist));
		file->next = NULL;
		file->tmp = ft_strdup(buf);
		//CHECKRETURN(!(ft_valide(file->tmp)), NULL);
		read(fd, buf, 1);
		if (buf[0] != '\n')
		{
			head = file->next;
			file->next = file;
		}
	}
	return (file);
}
