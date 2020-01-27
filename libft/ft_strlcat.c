/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:59:39 by vlobunet          #+#    #+#             */
/*   Updated: 2017/10/24 19:59:43 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*dnew;
	const char	*snew;
	size_t		nnew;
	size_t		dlen;

	dnew = dest;
	snew = src;
	nnew = size;
	while (nnew-- != 0 && *dnew != '\0')
		dnew++;
	dlen = dnew - dest;
	nnew = size - dlen;
	if (nnew == 0)
		return (dlen + ft_strlen(snew));
	while (*snew != '\0')
	{
		if (nnew != 1)
		{
			*dnew++ = *snew;
			nnew--;
		}
		snew++;
	}
	*dnew = '\0';
	return (dlen + (snew - src));
}
