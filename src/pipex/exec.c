/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:41:03 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/11 13:33:25 by diemorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pipex.h"


void exec(char *path, char **args, int in, int out, char **env)
{
    int pid = fork();

    if (pid == 0)
    {
        dup2(in, 0);    // ler
        dup2(out, 1);  // escreve
        if (in != 0)
            close(in);
        if(out != 1)
            close(out);
        execve(path, args, env);
        exit(127);
    }
    if (in != 0)
          close(in);
    if (out != 1)
         close(out);
}



void exec_pipe(t_pipe **pipex, char **env)
{

    int fd[2];

    pipe(fd);
    char *path;
    path = ft_strjoin((*pipex)->commands->path,(*pipex)->commands->commands[0]);
    exec(path,(*pipex)->commands->commands, (*pipex)->infile, fd[1],env);
    free(path);
    path = ft_strjoin((*pipex)->commands->next->path,(*pipex)->commands->next->commands[0]);
    exec(path,(*pipex)->commands->next->commands, fd[0], (*pipex)->outfile,env);
    free(path);
    free_s(pipex);
    wait(NULL);
    exit(0);
}
