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

void free_paths(char **paths)
{
   int i;
   i = 0;
   while(paths[i] != NULL)
   {
      free(paths[i]);
      i++;
   }
   free(paths);
}


char *ask_acess(char *comand, char *path)
{
   char **paths;
   int i;
   char *cplusp;
   paths = mysplit(path,':');
   i = 0;
   while(paths[i])
   {
      cplusp = ft_strjoin(paths[i],comand);
      if(access(cplusp,F_OK) == 0)
      {
         free(cplusp);
         cplusp = ft_strdup(paths[i]);
         free_paths(paths);
         return(cplusp);
      }
      i++;
   }
      return(NULL);
}


void free_pipe(t_pipe **pipex)
{





}