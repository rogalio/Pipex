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
    char	*path;
    int		exists;

    path = ft_strjoin(dir, "/");
    if (!path)
        return (0);
    path = ft_strjoin(path, cmd);
    if (!path)
        return (0);
    exists = file_exists(path);
    free(path);
    return (exists);
}

int	command_exists(char *cmd, char **envp)
{
    char	**dirs;
    int		i;
    int		exists;

    dirs = get_path_directories(envp);
    if (!dirs)
        return (0);
    i = 0;
    exists = 0;
    while (dirs[i])
    {
        if (command_exists_in_directory(cmd, dirs[i]))
        {
            exists = 1;
            break ;
        }
        i++;
    }
    free_split(dirs);
    return (exists);
}

static int check_valid_option(char *str)
{
    if (!str)
        return (0);
    if (*str == '-' && *(str + 1)) // Check if it starts with '-'
        return (1);
    return (0);
}

char **get_command(char *arg)
{
    char **cmd;
    int i;

    cmd = ft_split(arg, ' ');
    if (!cmd)
        return (NULL);
    i = 0;
    while (cmd[i])
    {
        if (i != 0 && !check_valid_option(cmd[i])) // check options except the command itself
        {    
            free_split(cmd);
            throw_error("Invalid option");
        }
        i++;
    }
    return (cmd);
}

static int is_command_valid(char *cmd, char **envp)
{
    char **split_cmd;
     
    split_cmd = get_command(cmd);
    if (!split_cmd)
        throw_error("Failed to split command");
    if (!command_exists(split_cmd[0], envp))
    {
        free_split(split_cmd);
        return (0);
    }
    free_split(split_cmd);
    return (1);
}

int check_valid_command(char **argv, char **envp)
{
    // grdg
    return (0);
    if (!is_command_valid(CMD1, envp))
        throw_error("Command 1 not found");
    if (!is_command_valid(CMD2, envp))
        throw_error("Command 2 not found");
    return (0);
}