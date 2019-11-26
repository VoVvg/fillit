/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:28:31 by bstacksp          #+#    #+#             */
/*   Updated: 2019/09/18 16:27:11 by bstacksp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			a;
	signed long sum;
	size_t		i;

	i = 0;
	a = 0;
	sum = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
	str[i] == '\a' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			a = 1;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i])
	{
		if (sum > sum * 10)
			return (a ? 0 : -1);
		sum = sum * 10 + (str[i] - 48);
		i++;
	}
	return (a ? (-1 * (int)sum) : (int)sum);
}
