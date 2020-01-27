ifeq ($(HOSTTYPE), )
	HOSTTYPE :=  $(shell uname -m)_$(shell uname -s)
endif

SRCDIR = srcs
OBJDIR = objs

MALLOC_NAME = libft_malloc_$(HOSTTYPE).so
SYMLINK_NAME = libft_malloc.so
NAME = main
SRCS = $(SRCDIR)/malloc.c $(SRCDIR)/show_alloc_mem.c $(SRCDIR)/log_file.c \
		$(SRCDIR)/log_name.c $(SRCDIR)/free.c $(SRCDIR)/checksum.c \
		$(SRCDIR)/srch_and_split.c $(SRCDIR)/pages.c $(SRCDIR)/headers.c \
		$(SRCDIR)/own_ptr.c $(SRCDIR)/realloc.c $(SRCDIR)/show_alloc_mem_src.c

OBJS = $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.c=.o))
FLAGS = -Wall -Werror -Wextra -O3

all: $(NAME)

main: $(OBJS)
	@make -C libft/
	@gcc $(FLAGS) $(OBJS) -shared -Llibft -lft -I includes -o $(MALLOC_NAME)
	@ln -sF $(MALLOC_NAME) $(SYMLINK_NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@gcc $(FLAGS) -c $< -o $@ 
clean:
	@make -C libft/ clean
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(MALLOC_NAME)
	@rm -f $(SYMLINK_NAME)

re: fclean all

.PHONY: all clean fclean re main
