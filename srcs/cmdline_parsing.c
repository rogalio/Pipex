#include "pipex.h"

int args_count_valid(int argc)
{
    if (argc != 5)
    {
        ft_putstr_fd("Error: wrong number of arguments\n", 2); 
        exit(1);
    }
    return (0);
}

int check_valid_arguments(int argc,char **argv, char **envp)
{
    
    args_count_valid(argc);
    check_file(INFILE, R_OK);
    check_file(OUTFILE, W_OK);
    check_valid_command(argv, envp);
    return (0);
}
