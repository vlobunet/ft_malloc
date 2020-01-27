/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 10:57:55 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 10:57:57 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void	push_event(char *event)
{
	if (g_mem.fd != -1)
	{
		ft_putstr_fd("\t:", g_mem.fd);
		ft_putendl_fd(event, g_mem.fd);
	}
}

void	push_time(char *event)
{
	if (g_mem.fd != -1)
	{
		time(&g_mem.rawtime);
		g_mem.timeinfo = localtime(&g_mem.rawtime);
		ft_putstr_fd(asctime(g_mem.timeinfo), g_mem.fd);
		push_event(event);
	}
}

void	push_data_in_log(t_page *page)
{
	t_header	*header;

	if (g_mem.fd == -1)
		return ;
	ft_putstr_fd(R_LEVEL_1, g_mem.fd);
	ft_putstr_fd("Page:\n", g_mem.fd);
	ft_putstr_fd(R_LEVEL_2, g_mem.fd);
	print_addr(page, 1, g_mem.fd);
	header = page->blocks;
	ft_putstr_fd(R_LEVEL_1, g_mem.fd);
	ft_putendl_fd("Headers: ", g_mem.fd);
	while (header)
	{
		check((void*)&header, sizeof(t_header));
		ft_putstr_fd(R_LEVEL_2, g_mem.fd);
		print_header(header, g_mem.fd);
		header = header->next;
	}
}

void	close_log_file(void)
{
	if (g_mem.fd != -1)
	{
		close(g_mem.fd);
	}
}

int		open_log_file(void)
{
	int		fd;
	char	*tmp;
	char	*ret;

	g_mem.fd = open(".delme", O_WRONLY | O_CREAT | O_APPEND, 0600);
	time(&g_mem.rawtime);
	g_mem.timeinfo = localtime(&g_mem.rawtime);
	tmp = create_log_name();
	ret = ft_strjoin(PATH, tmp);
	if ((fd = open(ret, O_WRONLY | O_CREAT | O_APPEND, 0600)) == -1)
	{
		ft_strdel(&tmp);
		ft_strdel(&ret);
		ft_putendl_fd("ERROR: LOGFile could not be created/opened.", 2);
		return (fd);
	}
	ft_strdel(&tmp);
	ft_strdel(&ret);
	close(g_mem.fd);
	g_mem.p = NULL;
	g_mem.fd = fd;
	return (1);
}
