/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:04:13 by bstacksp          #+#    #+#             */
/*   Updated: 2019/09/18 16:27:11 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	cp;
	char	*cpy;

	j = 0;
	cp = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	if (j == ft_strlen(s))
	{
		cpy = ft_memalloc(1);
		return (cpy);
	}
	if (!(cpy = ft_memalloc(i - j + 2)))
		return (NULL);
	while (s[j] != '\0' && j < i + 1)
		cpy[cp++] = s[j++];
	return (cpy);
}
