#include "pipex.h"


int main(int argc, char **argv, char **envp)
{   
    check_valid_arguments(argc, argv);
    create_pipes(argv, envp);

   return (0);
}