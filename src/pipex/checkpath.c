/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:26:07 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/11 14:28:00 by diemorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pipex.h"


char *checkpath(char **path, char *command)
{
    int i = 0;
    char *path_value = NULL;
    char *comandf;

    while(path[i] != NULL)
    {
        comandf = ft_strjoin("/",command);
        path_value = ft_strjoin(path[i], comandf);
        if(access(path_value, F_OK) == 0)
        {
            free(path_value);
            free(comandf);
            return (ft_strdup(path[i]));
        }
        free(path_value);
        free(comandf);
        i++;
    }
    perror("Comando nao encontrado\n");
    return NULL;
}

void get_commands(t_pipe **pipex, char *path,int ac,char **av)
{
    int i;
    i = 2;
   while(i != (ac - 1))
   {
        if(i == 2)
        {
            (*pipex)->commands =  new_cmd(ft_split(av[i], ' '),path);
        }
        else
        add_backcmd(ft_split(av[i], ' '),&(*pipex)->commands,path);
    i++;
   }

}


void parse_progam(int ac,char **av,char **env, t_pipe **pipex)
{
    char *path;
    char *fcommand;

    char *okpath;
    fcommand = ft_strjoin("/",av[2]);
    path = ft_getenv(env);
    path = ask_acess(fcommand,path);
    get_commands(pipex,path,ac,av);
    exec_pipe(pipex,env);
}
