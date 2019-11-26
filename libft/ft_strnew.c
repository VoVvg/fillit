/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 09:44:58 by bstacksp          #+#    #+#             */
/*   Updated: 2019/09/18 20:01:14 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;

	if (size + 1 == 0)
		return (NULL);
	if (!(string = ft_memalloc(size + 1)))
		return (NULL);
	return (string);
}
