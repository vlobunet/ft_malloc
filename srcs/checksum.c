/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 10:56:06 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 10:56:08 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

unsigned char	get_char(unsigned char *adr, int size, int flag)
{
	int				i;
	unsigned char	c;

	i = 0;
	c = 0;
	while (i < size)
	{
		c = (flag ? c + *adr : c * *adr);
		adr++;
		i++;
	}
	return (c & 255);
}

void			create(t_key **k, unsigned char buff[2], void **adr, int size)
{
	t_key	*tmp;
	void	*address;

	address = *adr;
	if (k)
	{
		tmp = *k;
		tmp->value[0] = get_char((unsigned char*)address, size, 1);
		tmp->value[1] = get_char((unsigned char*)address, size, 0);
	}
	else if (buff)
	{
		buff[0] = get_char((unsigned char*)address, size, 1);
		buff[1] = get_char((unsigned char*)address, size, 0);
	}
}

void			update(void **adr, int size)
{
	t_key	*key;

	key = (*adr + size);
	create(&key, NULL, adr, size);
}

void			check(void **adr, int size)
{
	unsigned char	key[2];
	t_key			*adr_key;

	create(NULL, key, adr, size);
	adr_key = (*adr + size);
	if (key[0] == adr_key->value[0] && key[1] == adr_key->value[1])
		return ;
	ft_putendl("ERRPR: Invalid checksum, exiting..");
	kill(getpid(), SIGSEGV);
}
