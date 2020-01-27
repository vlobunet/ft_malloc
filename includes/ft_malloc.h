/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:20:03 by vlobunet          #+#    #+#             */
/*   Updated: 2019/11/23 11:20:04 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define TINY 128
# define SMALL 2048
# define LARGE 0x0

# define TINY_MAX (8 * getpagesize())
# define SMALL_MAX (64 * getpagesize())
# define IS_TINY(x) (x <= TINY)
# define IS_SMALL(x) (x > TINY && x <= SMALL)
# define IS_LARGE(x) (x > SMALL)

# define PROT (PROT_READ | PROT_WRITE)
# define FLAGS (MAP_ANON | MAP_PRIVATE)

# define MMAP(size) (mmap(0, size, PROT, FLAGS, -1, 0))

# define R_LEVEL_1 "\t"
# define R_LEVEL_2 "\t\t\t"
# define R_LEVEL_3 "\t\t\t\t\t\t"

# define PATH "logfiles/"

# include <sys/mman.h>
# include <signal.h>
# include <pthread.h>
# include <time.h>
# include <fcntl.h>
# include <sys/types.h>
# include "../libft/includes/libft.h"

static pthread_mutex_t	g_mut = PTHREAD_MUTEX_INITIALIZER;

typedef struct		s_header
{
	size_t			size;
	void			*adr;
	char			free;
	struct s_header	*next;
	struct s_header	*prev;
}					t_header;

typedef struct		s_page
{
	char			type;
	size_t			available;
	t_header		*blocks;
	struct s_page	*next;
	struct s_page	*prev;
}					t_page;

typedef struct		s_key
{
	unsigned char	value[2];
}					t_key;

typedef struct		s_mem
{
	void			*root[2];
	size_t			ret[2];
	t_page			*p;
	int				fd;
	struct tm		*timeinfo;
	time_t			rawtime;
}					t_mem;

t_mem				g_mem;

int					open_log_file(void);
void				show_alloc_mem(void);
void				close_log_file(void);

void				print_addr(void *addr, int lf, int fd);
void				print_header(t_header *header, int fd);
char				*create_log_name(void);
void				push_data_in_log(t_page *page);

void				*malloc(size_t size);
void				*create_page(char type, size_t size_max, size_t size);
void				*create_lpage(char type, size_t size);

void				check(void **adr, int size);
void				update(void **adr, int size);
void				create(t_key **k, unsigned char buff[2], \
	void **adr, int size);
void				*srch_and_split(char type, size_t size);

void				*create_page(char type, size_t size_max, size_t size);
void				*create_lpage(char type, size_t size);

void				*create_header(void **root, t_page *page, \
	size_t size, char free);
void				fill(void **root, t_page *page);

void				free(void *ptr);
int					own_ptr(void *ptr);
void				*realloc(void *ptr, size_t size);

void				print_messages(char *str);
size_t				print_page(char type, int fd);
void				print_header(t_header *header, int fd);
void				print_conver_size(size_t bytes, int fd);
void				print_size(size_t size, char *type, int fd);
void				print_type(char type, int fd);

#endif
