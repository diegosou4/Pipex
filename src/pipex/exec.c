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
    
    char *args[] = {"/ls", "-l", NULL};
    char *path;
    char *comand;

    char *path2 = ft_strjoin((*pipex)->path, args[0]);
    pid_t idFilho = fork();
    printf("%i---\n",idFilho);
    if(idFilho == 0)
    {
           execve(path2,args,env);
           printf("aax");
           exit(127);
    }
    printf("a\n");
 
}