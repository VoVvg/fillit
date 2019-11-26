/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapnfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 01:43:49 by bstacksp          #+#    #+#             */
/*   Updated: 2019/09/26 20:37:31 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapnfree(char **var, void *new_vol)
{
	void *tmp;

	tmp = new_vol;
	free(*var);
	*var = tmp;
}
