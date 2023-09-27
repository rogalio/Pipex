#include "pipex.h"

int get_env_var(char **envp, char *var)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(var);
    while (envp[i])
    {
        if (ft_strncmp(envp[i], var, len) == 0)
            return (i);
        i++;
    }
    return (-1);
}

static char	**get_path_directories(char **envp)
{
    int		index;
    char	**dirs;

    index = get_env_var(envp, "PATH");
    if (index == -1)
        return (NULL);
    dirs = ft_split(envp[index] + 5, ':');
    if (!dirs)
        return (NULL);
    return (dirs);
}

static int command_exists_in_directory(char *cmd, char *dir)
{
    char	*temp;
    char	*path;
    int		exists;

    temp = ft_strjoin(dir, "/");
    if (!temp)
        return (0);
    path = ft_strjoin(temp, cmd);
    free(temp); // Libérez la mémoire allouée par le premier ft_strjoin
    if (!path)
        return (0);
    exists = file_exists(path);

    free(path);
    return (exists);
}



char *get_command_path(char *cmd, char **envp)
{
    char	**dirs;
    int		i;
    char    *fullpath;

    dirs = get_path_directories(envp);
    if (!dirs)
        return (NULL);
    i = 0;
    while (dirs[i])
    {
        if (command_exists_in_directory(cmd, dirs[i]))
        {
            fullpath = ft_strjoin(dirs[i], "/");
            if (!fullpath)
                return (NULL);
            fullpath = ft_strjoin(fullpath, cmd);
            free_split(dirs);
            return (fullpath);
        }
        i++;
    }
    free_split(dirs);
    return (NULL);
}



char **get_command(char *arg)
{
    char **cmd;

    cmd = ft_split(arg, ' ');
    if (!cmd)
        return (NULL);
    return (cmd);
}


