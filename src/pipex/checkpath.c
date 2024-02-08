
#include "../../includes/pipex.h"


char *checkpath(char **path, char *command)
{
    int i = 0;
    char *path_value = NULL;

    while(path[i] != NULL)
    {
        if(access(ft_strjoin(path[i], command), F_OK) == 0)
        {
            path_value = ft_strdup(ft_strjoin(path[i], command));
            return path_value;
        }
        i++;
    }

    return NULL;
}