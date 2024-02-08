/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:42:56 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/08 10:33:50 by diemorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/pipex.h"

int main(int ac, char **av, char **env)
{
    if(ac < 4)
        return(0);
 
    t_pipe *pipex;
    int i;
    i = ft_dstrlen(av);
    pipex->infile = open(av[1], O_RDONLY);
    pipex->outfile = open(av[i - 1], O_RDONLY);
    pipex->sizecomands = ac - 3;
 
 
    return(0);
}
