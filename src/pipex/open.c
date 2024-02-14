/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:43:36 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/14 15:43:39 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	openfd(t_pipe *pipex, int ac, char **av)
{
	if (strcmp(av[1], av[(ac - 1)]) == 0)
	{
		printf_error("Error: same file for input and output\n");
		free(pipex);
		exit(0);
	}
	pipex->infile = open(av[1], O_RDWR, 0644);
	if (pipex->infile == -1)
	{
		perror("Error");
		free(pipex);
		exit(0);
	}
	pipex->outfile = open(av[(ac - 1)], O_WRONLY | O_CREAT, 0644);
	if (pipex->outfile == -1)
	{
		close(pipex->infile);
		free(pipex);
		perror("Error");
		exit(0);
	}
}
