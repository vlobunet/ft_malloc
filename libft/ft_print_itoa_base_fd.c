/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_itoa_base_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:22:55 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 11:22:57 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen_base(int n, int base)
{
	int len;

	len = 0;
	if (!n)
		return (1);
	while (n)
	{
		len += 1;
		n /= base;
	}
	return (len);
}

void	ft_print_itoa_base_fd(int n, int base, int fd)
{
	char	str[64];
	int		size;
	int		negative;

	if (!n || base < 2 || base > 16)
		return ;
	negative = 0;
	size = ft_intlen_base(n, base);
	ft_memset(str, '\0', 64);
	if (base == 10 && n < 0)
	{
		n = (-n);
		size += 1;
		negative = 1;
		str[0] = '-';
	}
	while (n)
	{
		size -= 1;
		str[size] = "0123456789ABCDEF"[n % base];
		n /= base;
	}
	ft_putstr_fd(str, fd);
}
