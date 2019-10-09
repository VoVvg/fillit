/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:07:46 by bstacksp          #+#    #+#             */
/*   Updated: 2019/09/18 16:27:11 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		digit;
	int		minus;
	char	*str;
	long	nb;

	i = ft_numlen(n);
	minus = (n < 0) ? 1 : 0;
	nb = (n < 0) ? -(long)n : n;
	if (!(str = ft_memalloc(i + 1)))
		return (NULL);
	str[i--] = '\0';
	if (minus)
		str[0] = '-';
	while (i >= minus)
	{
		digit = nb % 10;
		str[i--] = digit + 48;
		nb /= 10;
	}
	return (str);
}
