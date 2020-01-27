/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:37:22 by vlobunet          #+#    #+#             */
/*   Updated: 2017/10/24 20:37:26 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t l)
{
	char	*str1;
	char	*str2;
	char	*str3;
	size_t	n[2];

	if (!*little)
		return ((char *)big);
	str2 = (char *)big;
	n[0] = 0;
	while (*str2 && n[0] < l)
	{
		str1 = str2;
		n[1] = n[0];
		str3 = (char *)little;
		while (*str2 && *str3 && *str3 == *str2 && n[0]++ < l)
		{
			str2++;
			str3++;
		}
		if (!*str3)
			return (str1);
		str2 = str1 + 1;
		n[0] = n[1] + 1;
	}
	return (NULL);
}
