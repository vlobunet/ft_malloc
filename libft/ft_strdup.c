/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:01:24 by vlobunet          #+#    #+#             */
/*   Updated: 2017/12/05 16:01:24 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	dup = ft_strnew(ft_strlen(s1));
	if (s1)
	{
		while (s1[i] != '\0')
		{
			dup[i] = s1[i];
			i++;
		}
	}
	return (dup);
}
