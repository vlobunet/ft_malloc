/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srch_and_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:06:20 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 11:06:22 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void	update_available(t_page **page)
{
	t_page		*tmp;
	t_header	*header;
	size_t		total;

	tmp = *page;
	header = tmp->blocks;
	total = 0;
	while (header)
	{
		if (header->free == 1)
			total += header->size;
		header = header->next;
	}
	tmp->available = total;
}

void	split(t_page *page, t_header *header, size_t size)
{
	void	*root;
	size_t	available_size;

	root = header->adr;
	root += size;
	available_size = (header->size - (size + sizeof(t_header) + sizeof(t_key)));
	if (create_header(&root, page, available_size, 1) != NULL)
		header->size = size;
}

void	*get(t_page *page, size_t size)
{
	t_header	*header;

	header = page->blocks;
	while (header)
	{
		check((void*)&header, sizeof(t_header));
		if (header->free == 1 && header->size >= size)
		{
			if (header->size > size && \
				(header->size - size) > (sizeof(t_header) + sizeof(t_key)))
				split(page, header, size);
			header->free = 0;
			update_available(&page);
			update((void*)&header, sizeof(t_header));
			update((void*)&page, sizeof(t_page));
			return (header->adr);
		}
		header = header->next;
	}
	return (NULL);
}

void	*srch_and_split(char type, size_t size)
{
	t_page	*page;
	void	*addr;

	page = g_mem.p;
	while (page)
	{
		check((void*)&page, sizeof(t_page));
		if (page->type == type && page->available >= size)
		{
			addr = get(page, size);
			if (addr)
				return (addr);
		}
		page = page->next;
	}
	return (NULL);
}
