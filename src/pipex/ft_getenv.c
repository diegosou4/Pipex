/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:29:14 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/06 17:29:15 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pipex.h"

char *ft_getenv(char **env)
{
    char *p;
    p = NULL;
    while(*env != NULL)
    {
        p = ft_strnstr(*env,"PATH=",5);
        if(p != NULL)
            return(p + 5);
        env++;
    }
    return(NULL);
}