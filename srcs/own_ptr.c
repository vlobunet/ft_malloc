/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   own_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:02:43 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 11:02:45 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

t_page		*search_padr(void *adr, t_page *p)
{
	size_t	page_size;

	while (p)
	{
		if (p->type == 3)
		{
			if ((size_t)p->blocks->adr == (size_t)adr)
				return (p);
		}
		else
		{
			if (p->type == 1)
				page_size = ((size_t)p + (TINY_MAX - 1));
			else if (p->type == 2)
				page_size = ((size_t)p + (SMALL_MAX - 1));
			if ((size_t)adr > (size_t)p && (size_t)adr < page_size)
				return (p);
		}
		p = p->next;
	}
	return (NULL);
}

t_header	*search_hadr(void *adr, t_page *p)
{
	t_header	*header;

	header = p->blocks;
	while (header)
	{
		if ((size_t)adr == (size_t)header->adr)
			return (header);
		header = header->next;
	}
	return (NULL);
}

int			own_ptr(void *ptr)
{
	t_page		*pages;
	t_page		*ptr_page;
	t_header	*header;

	pages = g_mem.p;
	ptr_page = search_padr(ptr, pages);
	if (ptr_page)
	{
		header = search_hadr(ptr, ptr_page);
		if (header)
			return (1);
	}
	return (0);
}
