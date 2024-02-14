/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:36:21 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/11 13:38:10 by diemorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>

typedef struct cmd
{
	char		*path;
	char		**commands;

	struct cmd	*next;
}				t_cmd;

typedef struct pipe
{
	int			infile;
	int			outfile;
	struct cmd	*commands;
}				t_pipe;

void			openfd(t_pipe *pipex, int ac, char **av);

void			parse_progam(int ac, char **av, char **env, t_pipe **pipex);
void			get_commands(t_pipe **pipex, char *path, int ac, char **av);
void			check_spath(t_pipe **pipex);
char			*checkpath(char **path, char *command);
char			*ask_acess(char *comand, char *path);

t_cmd			*new_cmd(char **comands, char *path);
void			add_backcmd(char **comands, t_cmd **cmd, char *path);

char			*ft_getenv(char **env);
void			exec(t_cmd *cmd, int in, int out, char **env);
void			exec_pipe(t_pipe **pipex, char **env);

char			**mysplit(char const *s, char c);
void			printf_error(char *str);

// Free
void			free_mysplit(char **arr);
void			free_paths(char **paths);
void			free_s(t_pipe **pipex);
#endif