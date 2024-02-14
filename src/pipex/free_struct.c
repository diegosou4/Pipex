/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:43:23 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/14 17:32:24 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	free_s(t_pipe **pipex)
{
	t_cmd	*ptr;
	t_cmd	*next;

	ptr = (*pipex)->commands;
	while (ptr != NULL)
	{
		next = ptr->next;
		free(ptr->path);
		free_mysplit(ptr->commands);
		free(ptr);
		ptr = next;
	}
	free(*pipex);
	*pipex = NULL;
}

void	free_mysplit(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
