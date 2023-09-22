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

void initialize_pipex_struct(t_pipex *pipex, char **argv)
{
    pipex->input_file = INFILE;
    pipex->output_file = OUTFILE;
    pipex->cmd1 = get_command(CMD1);
    pipex->cmd2 = get_command(CMD2);
    pipex->separator = '|';
}