/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:10:44 by bstacksp          #+#    #+#             */
/*   Updated: 2019/11/19 17:12:19 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	flistdel(t_flist *list)
{
	t_flist *fre;

	while (list)
	{
		fre = list;
		list = list->next;
		free(fre);
		ft_strdel(&fre->tmp);
	}
}
