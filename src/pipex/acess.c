/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acess.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:47:29 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/08 15:47:31 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pipex.h"


char *ask_acess(t_pipe **pipex,char **path, int indexcom)
{
   t_pipe *ptr;
    int i;
    char *str;
    i = 0;
   ptr = *(pipex);
    while(i != indexcom)
    {
        ptr = ptr->next;
        i++;
    }
    while(path[i] != NULL)
    {
        str = ft_strjoin("/",ptr->comands[0]);
        str = ft_strjoin(path[i] ,str);
        if(access(str,F_OK) == 0)
        {
            return(str);
        }
        i++;
    }
    return(NULL);
}

