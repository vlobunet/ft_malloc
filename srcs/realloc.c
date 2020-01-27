/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:03:58 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 11:04:06 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void	*repage(void *ptr, size_t size, t_header *header, t_page *p)
{
	void	*new_ptr;
	size_t	new_size;

	new_ptr = malloc(size);
	new_size = (header->size > size) ? size : header->size;
	ft_memcpy(new_ptr, ptr, new_size);
	if (p->type != 3)
	{
		print_messages("UPDATE PAGE[");
		header->free = 1;
		update((void*)&header, sizeof(t_header));
	}
	else
		free(ptr);
	return (new_ptr);
}

void	*realloc(void *ptr, size_t size)
{
	t_page		*page;
	t_header	*header;
	void		*addr;

	print_messages("REALLOC[");
	if (!ptr)
		return (malloc(size));
	if (!own_ptr(ptr))
		return (NULL);
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	pthread_mutex_lock(&g_mut);
	header = (ptr - (sizeof(t_header) + sizeof(t_key)));
	while (header->prev)
		header = header->prev;
	page = (void*)(header - 1);
	header = (ptr - (sizeof(t_header) + sizeof(t_key)));
	addr = repage(ptr, size, header, page);
	pthread_mutex_unlock(&g_mut);
	return (addr);
}
