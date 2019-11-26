/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:17:05 by bstacksp          #+#    #+#             */
/*   Updated: 2019/09/27 16:01:23 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	if (!(dest = malloc(ft_strlen(src) + 1)))
		return (NULL);
	if (dest != 0)
		ft_strcpy(dest, src);
	return (dest);
}
