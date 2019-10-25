/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:46:35 by bstacksp          #+#    #+#             */
/*   Updated: 2019/10/25 22:53:57 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"

typedef struct		s_flist
{
	struct s_flist	*next;
	char			*grid;
	char			**tet;
	char			c;
	int				height;
	int				width;
	int				map_size;
}					t_flist;

#endif
