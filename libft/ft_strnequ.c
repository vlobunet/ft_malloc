/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:10:24 by vlobunet          #+#    #+#             */
/*   Updated: 2017/10/25 19:10:29 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	res;

	if (s1 && s2)
	{
		res = ft_strncmp(s1, s2, n);
		if (res == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
