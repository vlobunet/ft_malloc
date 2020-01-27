/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:38:38 by vlobunet          #+#    #+#             */
/*   Updated: 2017/10/24 19:38:50 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t len)
{
	char *s;

	s = dest;
	while (*s != '\0')
		s++;
	while (len > 0 && *src != '\0')
	{
		*s++ = *src++;
		len--;
	}
	*s = '\0';
	return (dest);
}
