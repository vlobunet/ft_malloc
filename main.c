/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:24:08 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 11:24:10 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_malloc.h"

int	main(int argc, char const *argv[])
{
	void *c;
	void *d;

	open_log_file();
	c = malloc(1024 * 1024 * 1024);
	d = malloc(1);
	free(c);
	free(d);
	show_alloc_mem();
	close_log_file();
	return (0);
}
