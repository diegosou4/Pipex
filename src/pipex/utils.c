/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:30:00 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/08 12:30:01 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void printf_error(char *str)
{
    int i;
    static int j;
    i = ft_strlen(str);
    while(j != i)
        write(2, &str[j++],1);
}


char *simple_split(char *str, char sep)
{
    int j;
    j = 0;
    int i;
    char *newstr;
    i = ft_strlen(str);
    while(str[j])
    {
        if(str[j] == sep)
            break;
        j++;
    }
    if(j < i)
    {
      newstr = ft_substr(str,0,j);  
      return(newstr);
    }
    if(j >= i)
        return(str);
}

int pipesize(t_pipe **pipe)
{
    t_pipe *ptr;
    int i;
    i = 0;
    ptr = *(pipe);

    while(ptr != NULL)
    {
        ptr = ptr->next;
        i++; 
    }
    return(i);
}

t_cmd *new_cmd(char *comands)
{
    t_cmd *cmd;
    cmd = (t_cmd*) malloc(sizeof(t_cmd) * 1);
    if(cmd == NULL)
    {
        return(NULL);
    }
    cmd->commands = ft_strjoin("/",comands);
    if(cmd->commands == NULL)
    {
        free(cmd);
        return(NULL);
    }
    cmd->next = NULL;
    return cmd;
}

void add_backcmd(char *comands, t_cmd **cmd)
{
    t_cmd *ptr;
    t_cmd *last;

    last = new_cmd(comands);
    if(last == NULL)
        return;
    ptr = *(cmd);
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = last;
}