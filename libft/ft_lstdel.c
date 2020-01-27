/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:22:23 by vlobunet          #+#    #+#             */
/*   Updated: 2018/02/23 18:22:24 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **cur_lst)
{
	t_list *p;

	p = *cur_lst;
	(*cur_lst)->prev->next = (*cur_lst)->next;
	(*cur_lst)->next->prev = (*cur_lst)->prev;
	*cur_lst = (*cur_lst)->next;
	ft_strdel(&p->content);
	free(p);
}
