#include "pipex.h"


int main(int argc, char **argv, char **envp)
{   
    t_pipex pipex;
   
    check_valid_arguments(argc, argv,envp);
    initialize_pipex_struct(&pipex, argv, envp);
    create_pipes(&pipex);

    return (0);
}

