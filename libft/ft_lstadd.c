/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:21:29 by vlobunet          #+#    #+#             */
/*   Updated: 2018/02/23 18:21:30 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new_lst)
{
	if (*alst)
	{
		new_lst->next = (*alst)->next;
		new_lst->prev = *alst;
		if (!(*alst)->prev)
		{
			(*alst)->prev = new_lst;
			new_lst->next = *alst;
			(*alst)->next = new_lst;
		}
		else
		{
			(*alst)->next->prev = new_lst;
			(*alst)->next = new_lst;
		}
	}
	*alst = new_lst;
}
