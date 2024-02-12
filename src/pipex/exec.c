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
        dup2(in, 0);
        dup2(out, 1);
        if (in != 0)
            close(in);
        if (out != 1)
            close(out);
        execve(path, args, env);
        exit(127);
    }
    if (in != 1)
        close(in);
    if (out != 1)
        close(out);
}


void exec_pipe(t_pipe **pipex, char **env)
{
    char *args[] = {"/ls", NULL};
    char *path;
    char *comand;
    int fd[2];


    path = ft_strjoin((*pipex)->path,args[0]);
    pipe(fd);
    dup2((*pipex)->infile,fd[1]);

    exec(path,args,0,fd[1],env);

    int fd1[2];
    pipe(fd1);
    dup2((*pipex)->outfile,fd1[1]);
    
    char *args1[] = {"/wc", "-l", NULL};
    path = ft_strjoin((*pipex)->path,args1[0]);
    exec(path,args1,fd[1],fd1[1],env);
    wait(NULL);
    wait(NULL);
}