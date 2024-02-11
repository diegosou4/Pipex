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


char *ask_acess(t_pipe **pipex)
{

   char **paths;

   paths = ft_split((*pipex)->path, ':');
   free((*pipex)->path);
   (*pipex)->path = checkpath(paths, "ls");
}

