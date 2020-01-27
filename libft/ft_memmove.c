/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:59:19 by vlobunet          #+#    #+#             */
/*   Updated: 2017/12/05 15:59:19 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char *srcnew;
	char *dstnew;

	srcnew = (char*)src;
	dstnew = (char*)dest;
	if (srcnew < dstnew)
	{
		srcnew = srcnew + len - 1;
		dstnew = dstnew + len - 1;
		while (len > 0)
		{
			*dstnew-- = *srcnew--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*dstnew++ = *srcnew++;
			len--;
		}
	}
	return (dest);
}
