/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pages.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:03:26 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 11:03:28 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void	print_messages(char *str)
{
	ft_putstr_fd(str, g_mem.fd);
	ft_putnbr_fd((int)getpid(), g_mem.fd);
	ft_putendl_fd("]", g_mem.fd);
}

void	push_page(t_page *page)
{
	t_page	*tmp;

	tmp = g_mem.p;
	check((void*)&tmp, sizeof(t_page));
	while (tmp)
	{
		check((void*)&tmp, sizeof(t_page));
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	if (tmp)
		tmp->next = page;
	else
		tmp = page;
	update((void*)&tmp, sizeof(t_page));
	page->prev = tmp;
	update((void*)&page, sizeof(t_page));
}

void	*create_lpage(char type, size_t size)
{
	t_page	*p;
	t_key	*key;
	void	*addr;

	print_messages("CREATE_PAGE[");
	if ((addr = MMAP(sizeof(t_page) + sizeof(t_header) +
		(sizeof(t_key) * 2) + size)) == MAP_FAILED)
		addr = NULL;
	p = addr;
	p->type = type;
	p->available = size;
	p->blocks = NULL;
	p->next = NULL;
	p->prev = NULL;
	key = addr + sizeof(t_page);
	addr = key + sizeof(t_key);
	create(&key, NULL, (void*)&p, sizeof(t_page));
	if (!g_mem.p)
		g_mem.p = p;
	else
		push_page(p);
	addr = create_header(&addr, p, size, 0);
	push_data_in_log(p);
	return (addr);
}

void	*create_page(char type, size_t size_max, size_t size)
{
	t_page	*p;
	t_key	*key;
	void	*adr;

	print_messages("CREATE_PAGE[");
	if ((g_mem.root[type - 1] = MMAP(size_max)) == MAP_FAILED)
		g_mem.root[type - 1] = NULL;
	p = g_mem.root[type - 1];
	key = g_mem.root[type - 1] + sizeof(t_page);
	p->type = type;
	p->available = (size_max - (sizeof(t_page) + sizeof(t_key)));
	p->blocks = NULL;
	p->next = NULL;
	p->prev = NULL;
	g_mem.root[type - 1] = key + sizeof(t_key);
	create(&key, NULL, (void*)&p, sizeof(t_page));
	if (!g_mem.p)
		g_mem.p = p;
	else
		push_page(p);
	adr = create_header(&g_mem.root[type - 1], p, size, 0);
	fill(&g_mem.root[type - 1], p);
	push_data_in_log(p);
	return (adr);
}
