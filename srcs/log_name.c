/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 10:59:31 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 10:59:32 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

char	*get_prefix(int array[15], int i, char *prefix)
{
	char	*name;

	prefix = ft_strnew(15);
	while (i != 15)
	{
		prefix[i] = array[i] + '0';
		i++;
	}
	name = ft_strjoin("LOG_", prefix);
	ft_strdel(&prefix);
	return (name);
}

void	push_num(int array[15], int numb, int i)
{
	if (numb > 9)
		while (numb)
		{
			array[--i] = numb % 10;
			numb /= 10;
		}
	else
	{
		array[--i] = numb % 10;
		array[--i] = 0;
	}
}

char	*create_log_name(void)
{
	int	name_data[15];

	push_num(name_data, g_mem.timeinfo->tm_sec, 15);
	push_num(name_data, g_mem.timeinfo->tm_min, 13);
	push_num(name_data, g_mem.timeinfo->tm_hour, 11);
	name_data[8] = '_' - '0';
	push_num(name_data, g_mem.timeinfo->tm_mday, 8);
	push_num(name_data, g_mem.timeinfo->tm_mon, 6);
	push_num(name_data, 2019, 4);
	return (get_prefix(name_data, 0, NULL));
}
