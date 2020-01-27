/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 10:56:35 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 10:56:38 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

t_page	*get_page(t_header *header)
{
	t_page	*pages;

	pages = g_mem.p;
	while (pages)
	{
		if (pages->blocks == header)
			return (pages);
		pages = pages->next;
	}
	return (NULL);
}

void	free_large(t_page *page, t_header *header)
{
	print_messages("FREE[");
	page && page->prev ? page->prev->next = page->next : 0;
	page && page->prev ? update((void*)&page->prev, (sizeof(t_page))) : 0;
	page && page->next ? page->next->prev = page->prev : 0;
	page && page->next ? update((void*)&page->next, (sizeof(t_page))) : 0;
	page && !page->prev && page->next ? g_mem.p = page->next : 0;
	page && !page->prev && !page->next ? g_mem.p = NULL : 0;
	munmap(page, (sizeof(t_header) + sizeof(t_page) + header->size));
	page = NULL;
}

void	free(void *ptr)
{
	t_page		*page;
	t_header	*header;

	if (!ptr || !own_ptr(ptr))
		return ;
	pthread_mutex_lock(&g_mut);
	header = (ptr - (sizeof(t_header) + sizeof(t_key)));
	while (header && header->prev)
		header = header->prev;
	if (!(page = get_page(header)))
		return ;
	header = (ptr - (sizeof(t_header) + sizeof(t_key)));
	if (page->type == 3)
		free_large(page, header);
	else
	{
		page->available += header->size;
		header->free = 1;
		update((void*)&header, sizeof(t_header));
		update((void*)&page, sizeof(t_page));
	}
	pthread_mutex_unlock(&g_mut);
}
