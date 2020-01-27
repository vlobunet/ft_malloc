/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:00:16 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 11:00:18 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void	error_size(void)
{
	ft_putstr_fd("ERROR! ", g_mem.fd);
	ft_putstr_fd("PID: ", g_mem.fd);
	ft_putnbr_fd((int)getpid(), g_mem.fd);
	ft_putendl_fd(": Unacceptable size of allocated memory.", g_mem.fd);
	return ;
}

void	*malloc(size_t size)
{
	void	*ret;

	ret = NULL;
	if (size > 184467440716123995UL)
	{
		error_size();
		return (ret);
	}
	pthread_mutex_lock(&g_mut);
	if (size <= TINY)
	{
		if (!(ret = srch_and_split(1, size)))
			ret = create_page(1, (8 * getpagesize()), size);
	}
	else if (size > TINY && size <= SMALL)
	{
		if (!(ret = srch_and_split(2, size)))
			ret = create_page(2, (100 * getpagesize()), size);
	}
	else if (size > SMALL)
		ret = create_lpage(3, size);
	pthread_mutex_unlock(&g_mut);
	return (ret);
}
