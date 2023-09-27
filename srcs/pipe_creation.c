#include "pipex.h"

static void child_process(t_pipex *pipex, int *fd)
{

    
    int fdes = open(pipex->input_file, O_RDONLY);
    if (fdes == -1) {
        perror("Error opening input file");
        exit(1);
    }

    
    
    close(fd[0]);
    dup2(fdes, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fdes);
    close(fd[1]);

    char *args[] = {"cat", NULL};
    execve("/bin/cat", args, NULL);
    
    perror("Error executing child process");
    exit(1);
}

static void parent_process(t_pipex *pipex, int *fd)
{
    int status;
    waitpid(-1, &status, 0);

    printf("start of parent\n");
    
    int fdes = open(pipex->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fdes == -1) {
        perror("Error opening output file");
        exit(1);
    }

    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    dup2(fdes, STDOUT_FILENO);
    close(fd[0]);
    close(fdes);

    char *args[] = {"wc", "-w", NULL};
    execve("/usr/bin/wc", args, NULL);
    
    perror("Error executing parent process");
    exit(1);
}

int create_pipes(t_pipex *pipex)
{
    int fd[2];

    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        return (1);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return (1);
    }

    if (pid == 0)
        child_process(pipex, fd);
    else
        parent_process(pipex, fd);

    return (0);
}
