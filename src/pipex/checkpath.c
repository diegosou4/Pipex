/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:26:07 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/15 11:41:02 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	*checkpath(char **path, char *command)
{
	int		i;
	char	*path_value;
	char	*comandf;

	i = 0;
	path_value = NULL;
	while (path[i] != NULL)
	{
		comandf = ft_strjoin("/", command);
		path_value = ft_strjoin(path[i], comandf);
		if (access(path_value, F_OK) == 0)
		{
			free(path_value);
			free(comandf);
			return (ft_strdup(path[i]));
		}
		free(path_value);
		free(comandf);
		i++;
	}
	return (NULL);
}

void	get_commands(t_pipe **pipex, char *path, int ac, char **av)
{
	int	i;

	i = 2;
	while (i != (ac - 1))
	{
		if (i == 2)
		{
			(*pipex)->commands = new_cmd(ft_split(av[i], ' '), path);
		}
		else
			add_backcmd(ft_split(av[i], ' '), &(*pipex)->commands, path);
		i++;
	}
}

void	check_spath(t_pipe **pipex)
{
	t_cmd	*ptr;

	ptr = (*pipex)->commands;
	while (ptr != NULL)
	{
		if (ptr->path == NULL)
		{
			printf_error("Error: command not found\n");
			close((*pipex)->infile);
			close((*pipex)->outfile);
			free_s(pipex);
			exit(0);
		}
		ptr = ptr->next;
	}
}

void	parse_progam(int ac, char **av, char **env, t_pipe **pipex)
{
	char	*path;

	path = ft_getenv(env);
	if (path == NULL)
	{
		printf_error("Error: path not found\n");
		free((*pipex));
		exit(0);
	}
	get_commands(pipex, path, ac, av);
	check_spath(pipex);
	exec_pipe(pipex, env);
}
