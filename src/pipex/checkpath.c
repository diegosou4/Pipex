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
        path_value = ft_strdup(ft_strjoin(path[i], comandf));
        if(access(path_value, F_OK) == 0)
        {
            free(comandf);
            return path_value;
        }
        free(path_value);
        free(comandf);
        i++;
    }
    perror("Comando nao encontrado\n");
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

void parse_progam(int ac,char **av,char **env, t_pipe **pipex)
{
    (*pipex)->path = ft_getenv(env);

    ask_acess(pipex);
    if((*pipex)->path == NULL)
    {
        free(*pipex);        
    }
}