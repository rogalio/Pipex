#include "pipex.h"

static void child_process(t_pipex *pipex, int *fd)
{
    int input_fd;
  
    input_fd = open_file(pipex->input_file, O_RDONLY);
    
    close(fd[0]);
    dup2(input_fd, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(input_fd);
    close(fd[1]);

    execve(pipex->cmd1_path, pipex->cmd1, NULL);
    perror("Error executing child process");
    exit(1);
}

static void parent_process(t_pipex *pipex, int *fd)
{
    int status;
    int output_fd;


    waitpid(-1, &status, 0);
    output_fd = open_file(pipex->output_file, O_WRONLY | O_CREAT | O_TRUNC);

    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    dup2(output_fd, STDOUT_FILENO);
    close(fd[0]);
    close(output_fd);

    execve(pipex->cmd2_path, pipex->cmd2, NULL);
    perror("Error executing parent process");
    exit(1);
}


int create_pipes(t_pipex *pipex)
{
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) 
        throw_error("Error creating pipe");

    pid = fork();

    if (pid == -1)
        throw_error("Error Forking");
    if (pid == 0)
        child_process(pipex, fd);
    else
        parent_process(pipex, fd);

    return (0);
}
