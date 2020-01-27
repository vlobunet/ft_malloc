/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:34:44 by vlobunet          #+#    #+#             */
/*   Updated: 2017/10/24 16:34:55 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*srcnew;

	srcnew = (unsigned char*)s;
	while (n > 0 && *srcnew != (unsigned char)c)
	{
		n--;
		srcnew++;
	}
	if (n == 0)
		return (NULL);
	else
		return (srcnew);
}
