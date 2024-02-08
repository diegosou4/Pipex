/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:26:07 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/08 12:26:09 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pipex.h"


char *checkpath(char **path, char *command)
{
    int i = 0;
    char *path_value = NULL;

    while(path[i] != NULL)
    {
        if(access(ft_strjoin(path[i], command), F_OK) == 0)
        {
            path_value = ft_strdup(ft_strjoin(path[i], command));
            return path_value;
        }
        i++;
    }

    return NULL;
}

char **array_commands(int ac,char **av,t_pipe **pipex)
{
    int numc;
    numc = check_ac(ac);
    char **commands;
    static int i;
    i = numc;
    while(i != (ac - 1))
    {
        if(i == numc)
           *pipex = new_pipe(ft_split(av[i], ' '));
        else
        {
          add_back(ft_split(av[i], ' '),pipex);  
        }
        i += numc;
    }

     printf("Vamo ver ate aonde ta aqui");


}

void parse_progam(int ac,char **av,char **env)
{
    char *path_value;    
    t_pipe *pipex;
    pipex = NULL;
    
    array_commands(ac,av,&pipex);
    /*
    char **arg = ft_split(av[1],' ');
    comands = simple_split(av[1],' ');
    path_value = NULL;
    path_value = ft_getenv(env);
    if(path_value == NULL)
    {
        write(2,"Path nao encontrado",19);
        return(-1);
    }
    char **arr;
    char *path;
    arr = ft_split(path_value,':');
    path = checkpath(arr, ft_strjoin("/", comands));
    int fd[2];


    execve(path,arg,env);
*/


}