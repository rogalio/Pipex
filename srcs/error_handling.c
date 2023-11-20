#include "pipex.h"

void throw_error(char *msg)
{
    ft_putstr_fd("Error: ", 2);
    ft_putstr_fd(msg, 2);
    ft_putstr_fd("\n", 2);
    exit(1);
}

void throw_error_and_free(char *msg, char **arr)
{
    free_split(arr);
    throw_error(msg);
}