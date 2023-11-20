#include "pipex.h"

static void child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY, 0777);
   
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

static void parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		throw_error("Error opening file");
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}


int create_pipes(char **argv, char **envp)
{

    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) 
        throw_error("Error creating pipe");

    pid = fork();

    if (pid == -1)
        throw_error("Error Forking");
    if (pid == 0)
        child_process(argv,envp,fd);
    waitpid(pid, NULL, 0);
    parent_process(argv,envp,fd);

    return (0);
}