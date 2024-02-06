#include <unistd.h>
#include <stdio.h>

// Execv ele basicamente consegue executar outro programa que voce possa ter
// exec( *PATH, ARGS) eai voce passa os argumentos que ele precisa para rodar o progama


int main(int ac,char *av[])
{
   printf ("\n\nI am the parent process\n");
   char *arg_PTR[4];

   arg_PTR[0] = " child.c";
   arg_PTR[1] = " \nHello from ";
   arg_PTR[2] = " Process";
   arg_PTR[3] = NULL;

   execv("/home/diegmore/Desktop/git/Pipex/execv.bin",arg_PTR);

    return(0);

}