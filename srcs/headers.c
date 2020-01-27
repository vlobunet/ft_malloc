/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 10:57:23 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 10:57:25 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void	push_header(t_page *page, t_header *header)
{
	t_header	*tmp;

	check((void*)&page, sizeof(t_page));
	tmp = page->blocks;
	check((void*)&tmp, sizeof(t_header));
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if (tmp)
			check((void*)&tmp, sizeof(t_header));
	}
	tmp->next = header;
	update((void*)&tmp, sizeof(t_header));
	header->prev = tmp;
	update((void*)&header, sizeof(t_header));
}

void	fill(void **root, t_page *page)
{
	t_header	*header;
	t_key		*key;

	header = *root;
	*root = *root + sizeof(t_header);
	key = *root;
	*root = *root + sizeof(t_key);
	header->size = (page->available - (sizeof(t_header) + sizeof(t_key)));
	header->adr = *root;
	header->free = 1;
	header->next = NULL;
	header->prev = NULL;
	create(&key, NULL, (void*)&header, sizeof(t_header));
	*root = *root + page->available;
	check((void*)&header, sizeof(t_header));
	if (!page->blocks)
		page->blocks = header;
	else
		push_header(page, header);
	page->available -= sizeof(t_header) + sizeof(t_key);
	update((void*)&page, sizeof(t_page));
}

void	*create_header(void **root, t_page *page, size_t size, char free)
{
	t_header	*header;
	t_key		*key;

	header = *root;
	*root = *root + sizeof(t_header);
	key = *root;
	*root = *root + sizeof(t_key);
	header->size = size;
	header->adr = *root;
	header->free = free;
	header->next = NULL;
	header->prev = NULL;
	create(&key, NULL, (void*)&header, sizeof(t_header));
	*root = *root + size;
	if (!page->blocks)
		page->blocks = header;
	else
		push_header(page, header);
	if (free == 0)
		page->available -= (size + sizeof(t_header) + sizeof(t_key));
	else
		page->available -= (sizeof(t_header) + sizeof(t_key));
	update((void*)&page, sizeof(t_page));
	return (header->adr);
}
