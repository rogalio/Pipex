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

void check_file(char *filename, char permission)
{
    if (!file_exists(filename))
        throw_error("File does not exist");
    if (is_directory(filename))
        throw_error("Given path is a directory");
    if (!file_has_permission(filename, permission))
        throw_error("File does not have the required permissions");
}

int open_file(char *filename, int mode)
{
    int fd;

    if (mode == O_RDONLY)
        check_file(filename, R_OK);
    if (mode == O_WRONLY || mode == O_CREAT || mode == O_TRUNC)
        check_file(filename, W_OK);
    fd = open(filename, mode, 0644);
    if (fd == -1)
        throw_error("Error opening file");
    return (fd);
}