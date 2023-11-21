#include "pipex.h"

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		throw_error("Error creating pipe");
	pid = fork();
	if (pid == -1)
		throw_error("Error creating child process");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

/* Function who make a child process that will read from the stdin with
 get_next_line until it find the limiter word and then put the output inside a
 pipe. The main process will change his stdin for the pipe file descriptor. */
void	here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		usage();
	if (pipe(fd) == -1)
		throw_error("Error creating pipe");
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int main(int argc, char **argv, char **envp)
{   
    int i;
    int input_fd;
    int output_fd;


    if (argc >= 5)
    {
        if (ft_strncmp(argv[1], "here_doc", 8) == 0)
        {
            i = 3;
            output_fd = open_file(argv[argc - 1], 1);
            here_doc(argv[2], argc);
        }
        else 
        {
            i = 2;
            input_fd = open_file(argv[1], 2);
            output_fd = open_file(argv[argc - 1], 1);
            dup2(input_fd, STDIN_FILENO);
        }
        while (i < argc - 2)
            child_process(argv[i++], envp); 
        dup2(output_fd, STDOUT_FILENO);
        execute(argv[i], envp);
    }
    usage();
    return (0);
}