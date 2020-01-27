/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:18:56 by vlobunet          #+#    #+#             */
/*   Updated: 2018/02/23 18:18:57 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_colword(char const *str, char n)
{
	int	col;
	int	i;

	i = 0;
	col = 0;
	while (str[i] != '\0')
	{
		if (str[i] == n || str[i] == ' ')
			i++;
		else if (str[i] != n && (str[i + 1] == n || str[i + 1] == '\0'))
		{
			i++;
			col++;
		}
		else
			i++;
	}
	return (col);
}
