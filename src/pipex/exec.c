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

    printf("pid %i \n", pid);
    if (pid == 0)
    {
        dup2(in, 0);    // ler
        dup2(out, 1);  // escreve
        if (in != 0)
            close(in);
        if(in == 0 && out != 1)
            close(out);
        execve(path, args, env);
        exit(127);
    }
    if (in != 0)
    {
          close(in);
    }
    if (out != 1)
    {
         close(out);
    }
       
}


void exec_pipe(t_pipe **pipex, char **env)
{
    char *args[] = {"/ls", NULL};
    char *path;
    char *comand;

    char *path2 = ft_strjoin((*pipex)->path, args[0]);
    exec(path2,args,0,(*pipex)->infile,env);

    char *args2[] = {"/wc","-l", NULL};
    
    path2 = ft_strjoin((*pipex)->path, args2[0]);
    exec(path2,args2,(*pipex)->infile,(*pipex)->outfile,env);

    
    /*


    int fd1[2];

    pipe(fd);
    */
}