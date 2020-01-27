/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:02:08 by vlobunet          #+#    #+#             */
/*   Updated: 2017/12/05 16:02:09 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newmem;

	newmem = (char *)malloc(size + 1);
	if (newmem == NULL)
		return (NULL);
	ft_bzero(newmem, size + 1);
	return (newmem);
}
