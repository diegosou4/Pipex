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
   static int i;
   paths = ft_split(path, ':');
   new_path =  checkpath(paths,"ls");
   (*pipex)->path = new_path;
   while(paths[i] != NULL)
   {
      free(paths[i]);
      i++;
   }
   free(paths);
}


void free_pipe(t_pipe **pipex)
{





}