#include "pipex.h"

int file_exists(char *filename)
{
    struct stat buffer; 
    return (stat(filename, &buffer) == 0);
}

int is_directory(char *filename)
{
    struct stat buffer; 
    if (stat(filename, &buffer) == 0)
    {
        return S_ISDIR(buffer.st_mode);
    }
    return 0; 
}

int file_has_permission(char *filename, int mode)
{
    return access(filename, mode) == 0;
}

int has_txt_extension(char *filename)
{
    int i;

    i = 0;
    while (filename[i])
        i++;
    if (i < 5)
        return (0);
    if (filename[i - 1] == 't' && filename[i - 2] == 'x' && filename[i - 3] == 't' && filename[i - 4] == '.')
        return (1);
    return (0);
}

void check_file(char *filename, char permission)
{
    if (!file_exists(filename))
        throw_error("File does not exist");
    if (is_directory(filename))
        throw_error("Given path is a directory");
    if (!file_has_permission(filename, permission))
        throw_error("File does not have the required permissions");
    if (!has_txt_extension(filename))
        throw_error("File does not have the .txt required extension");
}

int open_file(char *filename, int mode)
{
    int fd;

    fd = open(filename, mode);
    if (fd == -1)
        throw_error("Error opening file");
    return (fd);
}

void close_file(int fd)
{
    if (close(fd) == -1)
        throw_error("Error closing file");
}

