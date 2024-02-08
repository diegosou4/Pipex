/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:41:03 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/08 15:41:04 by diegmore         ###   ########.fr       */
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


void exec_pipe(t_pipe **pipex, char **paths, char **env)
{
    t_pipe *ptr;
    char *path;
    path = ask_acess(pipex,paths, 0);
    int fd[2];
    ptr = *(pipex);
    pipe(fd);
    fd[1] = open("../../file1.txt", O_RDWR);
    exec(path, ptr->comands,0,fd[1],env);
    
    int fd2[2];
    pipe(fd2);
    fd[1] = open("../../file1.txt", O_RDWR);
    fd2[1] = open("../../file2.txt", O_RDWR);
    path = ask_acess(pipex,paths,1);
    ptr = ptr->next;
    exec(path, ptr->comands, fd[1], fd2[1], env);
    wait(NULL);
    wait(NULL);

}