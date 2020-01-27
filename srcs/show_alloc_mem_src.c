/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_src.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:18:20 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 11:18:21 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void	print_size(size_t size, char *type, int fd)
{
	ft_putnbr_fd(size, fd);
	ft_putstr_fd(type, fd);
}

void	print_conver_size(size_t bytes, int fd)
{
	size_t gigabyte;
	size_t megabyte;
	size_t kilobytes;

	kilobytes = bytes / 1024;
	bytes = bytes % 1024;
	megabyte = kilobytes / 1024;
	kilobytes = kilobytes % 1024;
	gigabyte = megabyte / 1024;
	megabyte = megabyte % 1024;
	ft_putstr_fd(" (", fd);
	if (gigabyte > 0)
		print_size(gigabyte, "Gb ", fd);
	if (megabyte > 0)
		print_size(megabyte, "Mb ", fd);
	if (kilobytes > 0)
		print_size(kilobytes, "Kb ", fd);
	print_size(bytes, "b)\n", fd);
}

void	print_header(t_header *header, int fd)
{
	print_addr(header, 0, fd);
	ft_putstr_fd(" - ", fd);
	print_addr((void*)((size_t)header + header->size), 0, fd);
	ft_putstr_fd(" : ", fd);
	ft_putnbr_fd(header->size, fd);
	print_conver_size(header->size, fd);
}

size_t	print_page(char type, int fd)
{
	t_page		*page;
	t_header	*header;
	size_t		total;

	page = g_mem.p;
	total = 0;
	while (page)
	{
		check((void*)&page, sizeof(t_page));
		if (page->type == type)
		{
			print_type(page->type, fd);
			print_addr(page, 1, fd);
			header = page->blocks;
			while (header)
			{
				check((void*)&header, sizeof(t_header));
				print_header(header, fd);
				total += (header->free == 0) ? header->size : 0;
				header = header->next;
			}
		}
		page = page->next;
	}
	return (total);
}
