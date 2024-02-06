/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:42:56 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/06 16:42:57 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/pipex.h"

int main(int ac, char **av, char **env)
{

    char *path_value;
    path_value = NULL;
    path_value = ft_getenv(env);
    if(path_value == NULL)
    {
        write(2,"Path nao encontrado",19);
        return(-1);
    }

    return(0);
}
