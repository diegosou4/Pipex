
#include "../../includes/pipex.h"

void openfd(t_pipe *pipex,int ac,char **av)
{
    pipex->infile = open(av[1], O_RDONLY, 0644);
    if(pipex->infile == -1)
    {
        perror("Error");
        exit(0);
    }
    pipex->outfile = open(av[ac - 1], O_RDONLY, 0644);
    if(pipex->outfile == -1)
    {
        close(pipex->infile);
        perror("Error");
        exit(0);
    }
}