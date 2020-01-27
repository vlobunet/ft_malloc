/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:04:42 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 11:04:44 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void	print_addr(void *addr, int lf, int fd)
{
	ft_putstr_fd("0x", fd);
	ft_print_itoa_base_fd((size_t)addr, 16, fd);
	if (lf)
		ft_putchar_fd('\n', fd);
}

void	print_type(char type, int fd)
{
	if (type == 1)
		ft_putstr_fd("TINY : ", fd);
	else if (type == 2)
		ft_putstr_fd("SMALL :", fd);
	else if (type == 3)
		ft_putstr_fd("LARGE : ", fd);
}

void	show_alloc_mem(void)
{
	size_t	total;

	pthread_mutex_lock(&g_mut);
	total = print_page(1, 1);
	total = total + print_page(2, 1);
	total = total + print_page(3, 1);
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putstr(" bytes");
	print_conver_size(total, 1);
	pthread_mutex_unlock(&g_mut);
}
