#include "pipex.h"

int args_count_valid(int argc)
{
    if (argc != 5)
        throw_error("Invalid number of arguments");
    return (0);
}

int check_valid_arguments(int argc,char **argv)
{   
    args_count_valid(argc);
    check_file(INFILE, R_OK);
    return (0);
}
