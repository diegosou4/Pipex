/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:11:25 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/12 14:11:26 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pipex.h"


void closefd(t_pipe **pipex)
{
    close((*pipex)->infile);
    close((*pipex)->outfile);
}

void free_commands(t_cmd **comands, t_pipe **pipex)
{
    t_cmd *ptr;
    t_cmd *next;

    ptr = (*comands);

    while(ptr != NULL)
    {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
    free(ptr);
    closefd(pipex);
}


