/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:08:19 by bstacksp          #+#    #+#             */
/*   Updated: 2019/10/09 18:05:23 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	static	char	*s[MAX_FD];
	char			buf[BUFF_SIZE + 1];
	int				ret;

	CHECKRETURN((fd < 0 || line == NULL || read(fd, buf, 0) < 0), -1);
	if (!s[fd])
		CHECKRETURN(!(s[fd] = ft_strnew(0)), -1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		ft_swapnfree(&s[fd], ft_strjoin(s[fd], buf));
		CHECKRETURN(!s[fd], -1);
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (!*s[fd])
		return (0);
	CHECKRETURN(!*(s[fd]) && ret < BUFF_SIZE, 0);
	CHECKRETURN(!(*line = ft_strsub(s[fd], 0, ft_strsnlen(s[fd]))), -1);
	(ft_strlen(*line) < ft_strlen(s[fd]) ? ft_swapnfree(&s[fd],
		ft_strdup(s[fd] + ft_strsnlen(s[fd]) + 1)) : ft_strdel(&s[fd]));
	return (1);
}
