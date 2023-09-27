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

char **split(char *str)
{
    char **arr;
    int i;
    int j;
    int k;

    arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
    if (!arr)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
        {
            k = 0;
            while (str[i + k] && str[i + k] != ' ')
                k++;
            arr[j] = (char *)malloc(sizeof(char) * (k + 1));
            if (!arr[j])
                return (NULL);
            k = 0;
            while (str[i] && str[i] != ' ')
                arr[j][k++] = str[i++];
            arr[j][k] = '\0';
            j++;
        }
        else
            i++;
    }
    arr[j] = NULL;
    return (arr);
}

static void assign_command_and_path(char ***cmd, char **cmd_path, char *arg, char **envp)
{
    *cmd = get_command(arg);
    if (!*cmd)
        throw_error("Error getting command");
    *cmd_path = get_command_path((*cmd)[0], envp);
    if (!*cmd_path)
        throw_error("Command not found");
}

void initialize_pipex_struct(t_pipex *pipex, char **argv, char **envp)
{
    pipex->input_file = INFILE;
    pipex->output_file = OUTFILE;
    assign_command_and_path(&pipex->cmd1, &pipex->cmd1_path, CMD1, envp);
    assign_command_and_path(&pipex->cmd2, &pipex->cmd2_path, CMD2, envp);
}