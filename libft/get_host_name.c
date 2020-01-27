/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_host_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudnik <vbudnik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:46:58 by vbudnik           #+#    #+#             */
/*   Updated: 2019/06/01 19:47:01 by vbudnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_host_name(void)
{
	char	str[128];

	if (gethostname(str, sizeof(str)) != -1)
		return (ft_strndup(str,\
			(ft_strlen(str) - ft_strlen(ft_strchr(str, '.')))));
	else
		return (NULL);
}
