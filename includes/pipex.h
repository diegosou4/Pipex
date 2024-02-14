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
	int			fd[2];
	struct cmd	*commands;
}				t_pipe;

char			*ft_getenv(char **env);
char			*checkpath(char **path, char *command);

void			exec(t_cmd *cmd, int in, int out, char **env);
int				check_ac(int ac);
void			get_commands(t_pipe **pipex, char *path, int ac, char **av);

void			printf_error(char *str);
void			parse_progam(int ac, char **av, char **env, t_pipe **pipex);
char			*simple_split(char *str, char sep);
void			exec_pipe(t_pipe **pipex, char **env);
void			openfd(t_pipe *pipex, int ac, char **av);
char			*ask_acess(char *comand, char *path);
char			*checkpath(char **path, char *command);
void			check_spath(t_pipe **pipex);
t_cmd			*new_cmd(char **comands, char *path);

void			free_commands(t_cmd **comands, t_pipe **pipex);
void			add_backcmd(char **comands, t_cmd **cmd, char *path);

void			free_paths(char **paths);
void			closefd(t_pipe **pipex);

char			**mysplit(char const *s, char c);

// Free
void			free_mysplit(char **arr);
void			free_s(t_pipe **pipex);
#endif