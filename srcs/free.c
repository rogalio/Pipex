#include "pipex.h"

// free cmds dans init_pipex_struct

void	free_split(char **tab)
{
	int i;

	if (!tab)
		return;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void free_pipex_resources(t_pipex *pipex)
{
    if (pipex->cmd1)
        free_split(pipex->cmd1);
   	if (pipex->cmd2)
		free_split(pipex->cmd2);
}