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
       error_handling.c

SRCDIR = srcs/
OBJS = $(addprefix $(SRCDIR), $(SRCS:.c=.o))

# Include directory
INCDIR = includes/
INCLUDES = -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(SRCDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re