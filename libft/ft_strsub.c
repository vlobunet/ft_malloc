/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:20:19 by vlobunet          #+#    #+#             */
/*   Updated: 2017/10/25 19:20:25 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s)
	{
		str = ft_strnew(len);
		if (str == NULL)
			return (NULL);
		s = s + start;
		i = 0;
		while (i < len)
		{
			str[i] = s[i];
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}
