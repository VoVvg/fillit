/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:02:35 by bstacksp          #+#    #+#             */
/*   Updated: 2019/12/01 19:28:39 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct				s_tetr_list
{
	char					tetr[4][4];
	char					letter;
	int						x_m;
	int						y_m;
	int						x;
	int						y;
	struct s_tetr_list		*next;
}							t_t_list;

int							solve_tetr(int fd);
int							init_int(int *a, int *b, int *c, int *d);
int							check_symbols(char *tetr);
int							is_valid_tetr(char *tetr, t_t_list *t_l);
int							read_tetr(int fd, t_t_list *t_l);
int							write_tetr(char *tetr, t_t_list *t_l);
int							insert(char **field, int x, int y, t_t_list *t_l);
int							clean_letter(int size, char **filed, char letter);
int							solver(int size, char **field, t_t_list *t_l);
char						**field_init(int size);
int							print_field(char **field, int size);
int							clean_tetr_list(t_t_list *t_l);
int							clean_filed(char ***field, int size);
int							ft_sqrt(int x);

#endif
