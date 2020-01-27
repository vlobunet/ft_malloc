/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:16:49 by vlobunet          #+#    #+#             */
/*   Updated: 2019/06/01 19:45:39 by vbudnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int nbr;
	int neg;

	i = 0;
	nbr = 0;
	neg = 0;
	if (!str)
		return (0);
	while (str[i] && ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r')))
		++i;
	if (str[i] && str[i] == '-')
		neg = 1;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		++i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += ((int)str[i] - '0');
		++i;
	}
	if (neg)
		nbr = -nbr;
	return (nbr);
}
