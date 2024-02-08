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

t_pipe  *new_pipe(char **command)
{
    t_pipe *pipe;

    pipe = (t_pipe*) malloc (sizeof(t_pipe) * 1);
    if(pipe == NULL)
        return(NULL);
    pipe->comands = command;
    pipe->next = NULL;
    return(pipe);

}

void add_back(char **command, t_pipe **pipe)
{
    t_pipe *ptr;
    t_pipe *last;

    last = new_pipe(command);
    if(last == NULL)
        return;
    ptr = *(pipe);
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = last;
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