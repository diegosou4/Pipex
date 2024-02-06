


#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>

int main(int argc, char *argv[])
{
 printf ("I am the child process");

 printf ("Argument 1: %s\n", argv[1]);
 printf ("Argument 2: %s\n", argv[2]);
 printf ("Argument 3: %s\n", argv[3]);

}