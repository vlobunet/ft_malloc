/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cursor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 19:59:38 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/23 19:59:40 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_cursor_y(void)
{
	char	bff[20];
	int		ret;

	ft_putstr("\033[6n");
	ret = read(0, bff, 20);
	bff[ret] = '\0';
	ret = ft_atoi(&bff[2]);
	return (ret);
}

int	get_cursor_x(void)
{
	char	bff[20];
	int		ret;

	ft_putstr("\033[6n");
	ret = read(0, bff, 20);
	bff[ret] = '\0';
	ret = ft_atoi(&bff[2 + ft_intlen(ft_atoi(&bff[2])) + 1]);
	return (ret);
}
