#include "pipex.h"


int main(int argc, char **argv, char **envp)
{   
    t_pipex pipex;

    check_valid_arguments(argc, argv,envp);
    initialize_pipex_struct(&pipex, argv);
    printf("command 1 and arguments: %s\n", pipex.cmd1[0]);

    return (0);
}

