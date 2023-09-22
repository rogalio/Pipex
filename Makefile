NAME = pipex

# Compilation flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files and objects
SRCS = main.c \
       pipex_utils.c \
       cmdline_parsing.c \
       file_handling.c \
       pipe_creation.c \
       child_processes.c \
       error_handling.c \
       free.c \
	   commands.c 

SRCDIR = srcs/
OBJS = $(addprefix $(SRCDIR), $(SRCS:.c=.o))

# Include directory
INCDIR = includes/
INCLUDES = -I$(INCDIR) -I./libft

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -L./libft -lft -o $(NAME)

$(SRCDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re