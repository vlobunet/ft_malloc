/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:33:19 by vlobunet          #+#    #+#             */
/*   Updated: 2017/10/24 15:33:27 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *srcnew;
	char *dstnew;

	srcnew = (char*)src;
	dstnew = (char*)dest;
	while (n > 0 && *srcnew != c)
	{
		n--;
		*dstnew++ = *srcnew++;
	}
	if (n > 0)
	{
		*dstnew++ = *srcnew++;
		return ((void*)dstnew);
	}
	else
		return (NULL);
}
