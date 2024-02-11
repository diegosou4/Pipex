/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:26:07 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/11 13:18:49 by diemorei         ###   ########.fr       */
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

void commands(int ac,char **av,t_pipe **pipex)
{
    int numc;
    char **commands;
    static int i;
    i = 2;
    while(i <= (ac - 2))
    {
        if(i == 2)
           *pipex = new_pipe(ft_split(av[i], ' '));
        else
        {
            add_back(ft_split(av[i], ' '),pipex); 
        }
           
        i++;
    }
}

void parse_progam(int ac,char **av,char **env)
{
    char *path_value;    
    t_pipe *pipex;
    pipex = NULL;
    char *path;
    path = ft_getenv(env);
    //  Protecao pro path


   // commands(ac,av,&pipex);
  //  pipex->path = ft_split(path,':');
 //   exec_pipe(&pipex,pipex->path,env);



    /*
    execve(path,arg,env);
    */

}