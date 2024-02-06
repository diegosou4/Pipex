
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <unistd.h>
#include  <errno.h>

int main (){
printf ("\n\nI am the parent process\n");
char *arg_Ptr[5];
arg_Ptr[0] = " child.c";
arg_Ptr[1] = " \nHello from ";
arg_Ptr[2] = " process 2 ";
arg_Ptr[3] = NULL;

execv("/home/diegmore/Desktop/git/Pipex/child.bin", arg_Ptr);
}