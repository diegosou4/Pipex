/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:30:00 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/15 14:33:48 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	printf_error(char *str)
{
	int			i;
	static int	j;

	i = ft_strlen(str);
	while (j != i)
		write(2, &str[j++], 1);
}

void	get_scommands(char **comands, char *path, t_cmd *cmd)
{
	char	*ptr;
	int		i;

	ptr = ask_command(comands[0]);
	if (ptr != NULL)
	{
		i = ft_intrchrs(ptr, 47);
		cmd->path = ft_substr(ptr, 0, i);
		cmd->commands = splitcase(ptr);
		free(ptr);
		free_mysplit(comands);
	}
	else
	{
		cmd->commands = comands;
		cmd->path = ask_acess(cmd->commands[0], path);
	}
}

t_cmd	*new_cmd(char **comands, char *path)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd) * 1);
	if (cmd == NULL)
	{
		return (NULL);
	}
	get_scommands(comands, path, cmd);
	if (cmd->commands == NULL)
	{
		free(cmd);
		return (NULL);
	}
	cmd->next = NULL;
	return (cmd);
}

void	add_backcmd(char **comands, t_cmd **cmd, char *path)
{
	t_cmd	*ptr;
	t_cmd	*last;

	last = new_cmd(comands, path);
	if (last == NULL)
		return ;
	ptr = *(cmd);
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = last;
}

void	print_erfile(char *str, char *file)
{
	int	i;

	i = 0;
	write(2, "Error: ", 8);
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, ": ", 2);
	i = 0;
	while (file[i] != '\0')
	{
		write(2, &file[i], 1);
		i++;
	}
	write(2, "\n", 1);
}
