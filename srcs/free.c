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
