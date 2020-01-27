/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:49:04 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/19 14:49:06 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_settolower(char *crs)
{
	char	*str;
	int		i;

	i = 0;
	if (crs && *crs)
	{
		str = ft_strdup(crs);
		while (crs[i])
		{
			str[i] = ft_tolower(crs[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
