NAME = pipex

# Compilation flags
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

# Source files and objects
SRCDIR = srcs/
OBJDIR = obj/
SRCS = pipex.c \
       pipex_utils.c \
       cmdline_parsing.c \
       file_handling.c \
       pipe_creation.c \
       error_handling.c \
       free.c \
       commands.c 
OBJS = $(SRCS:.c=.o)
OBJS_PREF = $(addprefix $(OBJDIR), $(OBJS))

# Include directory
INCDIR = includes/
INCLUDES = -I$(INCDIR) -I./libft

LIBFT = libft/libft.a

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS_PREF) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_PREF) -L./libft -lft -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re