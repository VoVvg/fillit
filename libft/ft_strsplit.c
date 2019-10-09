/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:23:17 by bstacksp          #+#    #+#             */
/*   Updated: 2019/09/18 16:27:11 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;
	int		neword;

	if (!s || !(words = (char **)malloc(sizeof(*words) *
		(ft_countwords(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_countwords(s, c))
	{
		neword = 0;
		if (!(words[i] = ft_memalloc(ft_wordlen(&s[j], c + 1))))
			words[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j] != '\0')
			words[i][neword++] = s[j++];
		words[i][neword] = '\0';
		i++;
	}
	words[i] = 0;
	return (words);
}
