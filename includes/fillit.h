/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:02:35 by bstacksp          #+#    #+#             */
/*   Updated: 2019/11/26 20:40:29 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef	struct				s_tlist
{
	char					tetr[4][4];
	char					letter;
	int						x_m;
	int						y_m;
	int						x;
	int						y;
	struct s_tlist			*next;
}							t_tlist;

int							check_symbols(char *tetr);
int							is_valid_tetr(char *tetr, t_tlist *t_l);
int							read_tetr(int fd, t_tlist *t_l);
int							write_tetr(char *tetr, t_tlist *t_l);
int							insert(char **field, int x, int y, t_tlist *t_l);
int							solver(int size, char **field, t_tlist *t_l);
char						**field_init(int size);
int							print_field(char **field, int size);
void						clearmass(char **res);
void						flistdel(t_tlist *list);
int							ft_check_open_file(int fd, int ac, char **av);
int							ft_check_count(int count);

#endif
