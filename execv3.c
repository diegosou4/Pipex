

#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <unistd.h>
#include  <errno.h>
#include <sys/wait.h>


// struct s_cmd
// {
//    char         *path;
//    char         **agrs;
//    int          fd[2];
//    struct s_cmd *next;
   
// };



void exec(char *path, char **args, int in, int out, char **env)
{
    int pid = fork();

    if (pid == 0)
    {
        dup2(in, 0);
        dup2(out, 1);
        if (in != 0)
            close(in);
        if (out != 1)
            close(out);
        execve(path, args, env);
        exit(127);
    }
    if (in != 0)
        close(in);
    if (out != 1)
        close(out);
}

int main(int argc, char **argv, char **env)
{


    int fd[2];


    pipe(fd);

    // printf("in: %i out: %i\n", fd[0], fd[1]);

    char *args[] = { "-la", NULL };

    exec("/bin/ls", args, 0, fd[1], env);

    char *args2[] = { "wc",  NULL };


    int fd2[2];


    pipe(fd2);


    exec("/usr/bin/wc", args2, fd[0], fd2[1], env);



    exec("/usr/bin/wc", args2, fd2[0], 1, env);

   
    wait(NULL);
    wait(NULL);
    // printf("sdds: %i\n", pid);

    // Se chegarmos aqui, houve um erro
    return 1;
}