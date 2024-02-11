/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:36:21 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/11 13:17:06 by diemorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

typedef struct pipe
{
    char *path;
    int infile;
    int outfile;
    char **comands;
    int sizecomands;
    struct pipe *next;
}           t_pipe;



char *ft_getenv(char **env);
char *checkpath(char **path, char *command);

void exec(char *path, char **args, int in, int out, char **env);
int check_ac(int ac);
void exec_pipe(t_pipe **pipex, char **paths, char **env);

void printf_error(char *str);
void parse_progam(int ac,char **av,char **env);
char *simple_split(char *str, char sep);
t_pipe  *new_pipe(char **command);
void exec_pipe(t_pipe **pipex, char **paths, char **env);
void openfd(t_pipe *pipex,int ac,char **av);
char *ask_acess(t_pipe **pipex,char **path, int indexcom);
void add_back(char **command, t_pipe **pipe);
#endif