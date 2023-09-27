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

static char *build_fullpath(char *dir, char *cmd)
{
    char *fullpath;
    char *temp;

    temp = ft_strjoin(dir, "/");
    if (!temp)
        return (NULL);

    fullpath = ft_strjoin(temp, cmd);
    free(temp);
    return (fullpath);
}

char *get_command_path(char *cmd, char **envp)
{
    char **dirs;
    int i;
    char *fullpath;

    dirs = get_path_directories(envp);
    if (!dirs)
        return (NULL);

    i = 0;
    while (dirs[i])
    {
        fullpath = build_fullpath(dirs[i], cmd);
        if (!fullpath)
            return (NULL);
        if (file_exists(fullpath))
        {
            free_split(dirs);
            return (fullpath);
        }
        free(fullpath);
        i++;
    }
    free_split(dirs);
    return (NULL);
}

char **get_command(char *arg)
{
    char **cmd;

    cmd = split(arg);
    if (!cmd)
        return (NULL);
    return (cmd);
}
