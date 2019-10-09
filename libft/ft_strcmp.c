/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:33:46 by bstacksp          #+#    #+#             */
/*   Updated: 2019/09/18 16:27:11 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	char	cmp1;
	char	cmp2;
	int		i;

	i = 0;
	while (*(s1 + i) != 0 && *(s1 + i) == *(s2 + i))
		i++;
	cmp1 = s1[i];
	cmp2 = s2[i];
	return ((unsigned char)cmp1 - (unsigned char)cmp2);
}
