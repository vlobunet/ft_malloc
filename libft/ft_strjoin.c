/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:01:39 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/16 13:33:24 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		l;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (s1 && s2)
	{
		l = ft_strlen(s1) + ft_strlen(s2) + 1;
		str = (char*)malloc(l * sizeof(char));
		if (!str)
			return (NULL);
		l = 0;
		while (*(s1) != '\0')
			str[l++] = *(s1++);
		while (*(s2) != '\0')
			str[l++] = *(s2++);
		str[l] = '\0';
		return (str);
	}
	return (NULL);
}
