/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:23:12 by vlobunet          #+#    #+#             */
/*   Updated: 2018/02/23 18:23:13 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int fd, int buf_size)
{
	t_list *lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->fd = fd;
	lst->content = ft_strnew(buf_size);
	lst->prev = lst;
	lst->next = lst;
	return (lst);
}
