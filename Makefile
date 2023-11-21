NAME = pipex
BONUS_NAME = pipex_bonus

# Compilation flags
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

# Source files and objects
SRCDIR = srcs/
OBJDIR = obj/
SRCS = pipex.c pipex_utils.c cmdline_parsing.c file_handling.c pipe_creation.c error_handling.c free.c commands.c
BONUS_SRCS = pipex_bonus.c pipex_utils_bonus.c cmdline_parsing.c file_handling.c pipe_creation.c error_handling.c free.c commands.c pipex_utils.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
OBJS_PREF = $(addprefix $(OBJDIR), $(OBJS))
BONUS_OBJS_PREF = $(addprefix $(OBJDIR), $(BONUS_OBJS))

# Include directory
INCDIR = includes/
INCLUDES = -I$(INCDIR) -I./libft

LIBFT = libft/libft.a

all: $(OBJDIR) $(NAME)

bonus: $(OBJDIR) $(BONUS_NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS_PREF) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_PREF) -L./libft -lft -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS_PREF) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS_PREF) -L./libft -lft -o $(BONUS_NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re