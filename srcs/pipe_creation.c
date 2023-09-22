#include "pipex.h"

static void child_process(t_pipex *pipex, int *fd)
{
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    execve(pipex->cmd1[0], pipex->cmd1, NULL);
    exit(1);
}

static void parent_process(t_pipex *pipex, int *fd)
{
    int status;

    waitpid(-1, &status, 0);
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    execve(pipex->cmd2[0], pipex->cmd2, NULL);
    exit(1);
}

int create_pipes(t_pipex *pipex)
{
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1)
        return (1);
    pid = fork();
    if (pid == -1)
        return (1);
    if (pid == 0)
        child_process(pipex, fd);
    else
        parent_process(pipex, fd);
    return (0);
}