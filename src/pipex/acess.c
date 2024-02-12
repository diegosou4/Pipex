/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acess.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:47:29 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/11 14:28:58 by diemorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pipex.h"


void *ask_acess(t_pipe **pipex, char *path)
{
   char **paths;
   char *new_path;
   char **comands;
   comands = ft_split((*pipex)->commands->commands, ' ');
   static int i;
   paths = ft_split(path, ':');
   new_path =  checkpath(paths,comands[0]);
   (*pipex)->path = new_path;
   while(paths[i] != NULL)
   {
      free(paths[i]);
      i++;
   }
   free(paths);
   i = 0;
   while (comands[i] != NULL)
   {
      free(comands[i]);
      i++;
   }
   free(comands);
}


void free_pipe(t_pipe **pipex)
{





}