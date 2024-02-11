/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:42:56 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/11 13:33:06 by diemorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/pipex.h"

int main(int ac, char **av, char **env)
{
    if(ac < 4)
        return(0);
 
    t_pipe *pipex;
    pipex = malloc(sizeof(t_pipe));
    openfd(pipex, ac, av);
    parse_progam(ac, av, env, &pipex);
    return(0);
}
