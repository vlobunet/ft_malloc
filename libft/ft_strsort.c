/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:04:21 by vlobunet          #+#    #+#             */
/*   Updated: 2017/11/01 19:04:26 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_selsort(char *str)
{
	int		i;
	int		j;
	char	sumb;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[j])
	{
		while (str[i + 1])
		{
			if (str[i] > str[i + 1])
			{
				sumb = str[i + 1];
				str[i + 1] = str[i];
				str[i] = sumb;
			}
			i++;
		}
		i = j;
		j++;
	}
	return (str);
}
