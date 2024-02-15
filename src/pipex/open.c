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
	if (ft_strcmp(av[1], av[(ac - 1)]) == 0)
	{
		printf_error(av[1]);
		write(2, " cannot overwrite existing file\n", 32);
		free(pipex);
		exit(0);
	}
	pipex->infile = open(av[1], O_RDWR, 0777);
	if (pipex->infile == -1)
	{
		print_erfile(strerror(errno), av[1]);
		free(pipex);
		exit(0);
	}
	pipex->outfile = open(av[(ac - 1)], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->outfile == -1)
	{
		close(pipex->infile);
		free(pipex);
		print_erfile(strerror(errno), av[(ac - 1)]);
		exit(0);
	}
}
