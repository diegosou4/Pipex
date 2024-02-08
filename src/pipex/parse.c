/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:26:15 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/08 12:26:16 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/pipex.h"

int check_ac(int ac)
{
    ac--;
    if(ac % 2 == 0 && ac >= 4)
        return((ac / 2));
    printf_error("Numero de Argumentos invalidos\n");
    exit(0);
}