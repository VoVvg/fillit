/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:31:13 by bstacksp          #+#    #+#             */
/*   Updated: 2019/09/18 16:27:11 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char		*cs;
	unsigned char	*cd;
	unsigned char	cc;
	size_t			i;

	i = 0;
	cc = (unsigned char)c;
	cs = src;
	cd = dst;
	while (i < n)
	{
		cd[i] = cs[i];
		if (cd[i] == cc)
			return (&cd[i + 1]);
		i++;
	}
	return (NULL);
}
