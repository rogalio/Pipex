#include "pipex.h"

int count_words(char *str)
{
    int i;
    int num_words;

    i = 0;
    num_words = 0;
    while (str[i])
    {
        if (str[i] != ' ')
        {
            num_words++;
            while (str[i] && str[i] != ' ')
                i++;
        }
        else
            i++;
    }
    return (num_words);
}

void initialize_pipex_struct(t_pipex *pipex, char **argv, char **envp)
{
    char *cmd1path;
    char *cmd2path;
    char **cmd1;
    char **cmd2;

    cmd1 = get_command(CMD1);
    cmd2 = get_command(CMD2);
    cmd1path = get_command_path(cmd1[0], envp);
    cmd2path = get_command_path(cmd2[0], envp);
    if (!cmd1path || !cmd2path)
        throw_error("Command not found");
    

    pipex->input_file = INFILE;
    pipex->output_file = OUTFILE;
    pipex->cmd1 = cmd1;
    pipex->cmd2 = cmd2;
    pipex->cmd1_path = cmd1path;
    pipex->cmd2_path = cmd2path;

    printf("input file: %s\n", pipex->input_file);
    printf("output file: %s\n", pipex->output_file);
    printf("cmd1: %s\n", pipex->cmd1[0]);
    printf("cmd2: %s\n", pipex->cmd2[0]);
    printf("cmd1 path: %s\n", pipex->cmd1_path);
    printf("cmd2 path: %s\n", pipex->cmd2_path);


    free_split(cmd1);
    free_split(cmd2);
}