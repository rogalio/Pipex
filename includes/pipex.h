#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <signal.h>
# include <stdlib.h> 

#define INFILE argv[1]
#define OUTFILE argv[4]
#define CMD1 argv[2]
#define CMD2 argv[3]

/*
** Structures, si nécessaires
*/

typedef struct s_pipex
{
    char *input_file;
    char *output_file;
    char **cmd1;
    char **cmd2;
    char separator;
    int *pipes;
    int *pids;
} t_pipex;



// Fonctions utilitaires de pipex_utils.c
int count_words(char *str);
void initialize_pipex_struct(t_pipex *pipex, char **argv);

// Fonctions d'analyse de la ligne de commande de cmdline_parsing.c
int args_count_valid(int argc);
char **get_command(char *arg);
int check_valid_arguments(int argc,char **argv, char **envp);

// Fonctions de gestion des fichiers de file_handling.c
int file_exists(char *filename);
int is_directory(char *filename);
int file_has_permission(char *filename, int mode);
int has_txt_extension(char *filename);
void check_file(char *filename, char permission);
int open_file(char *filename, int mode);
void close_file(int fd);

// Fonctions de gestion des commandes de commands.c
int check_valid_command(char **argv,char **envp);

// Fonctions de création et gestion des pipes de pipe_creation.c
int create_pipes(t_pipex *pipex);

// Fonctions d'exécution des commandes pour les processus enfants de child_processes.c

// Fonctions de gestion des erreurs de error_handling.c
void throw_error(char *msg);

// Fonctions de gestion de la mémoire de free.c
void	free_split(char **tab);
void free_pipex_resources(t_pipex *pipex);



#endif