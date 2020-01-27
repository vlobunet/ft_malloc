/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudnik <vbudnik@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 19:46:24 by vbudnik           #+#    #+#             */
/*   Updated: 2019/06/01 19:46:26 by vbudnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsdel(char *s1, char *s2, char *s3, char *s4)
{
	ft_strdel(&s1);
	ft_strdel(&s2);
	ft_strdel(&s3);
	ft_strdel(&s4);
}
