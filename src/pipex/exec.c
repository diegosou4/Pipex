/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:41:03 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/14 17:31:49 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	exec(t_cmd *cmd, int in, int out, char **env)
{
	int		pid;
	char	*path;

	pid = fork();
	path = ft_strjoin(cmd->path, cmd->commands[0]);
	free(cmd->path);
	cmd->path = path;
	if (pid == 0)
	{
		dup2(in, 0);
		dup2(out, 1);
		if (in != 0)
			close(in);
		if (out != 1)
			close(out);
		execve(path, cmd->commands, env);
		exit(127);
	}
	if (in != 0)
		close(in);
	if (out != 1)
		close(out);
}

void	exec_pipe(t_pipe **pipex, char **env)
{
	int	fd[2];

	pipe(fd);
	exec((*pipex)->commands, (*pipex)->infile, fd[1], env);
	exec((*pipex)->commands->next, fd[0], (*pipex)->outfile, env);
	free_s(pipex);
	wait(NULL);
	exit(0);
}
