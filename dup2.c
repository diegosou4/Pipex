#include<stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 

//  A diferenca que no dup2 eu posso falar o valor do fd

int main()
{
    int fd_one;

    fd_one = open("file.txt", O_WRONLY | O_APPEND);

    int fd_two;

    fd_two = dup2(fd_one,22);
    printf("%i fd_one \n",fd_one);
    printf("%i fd_two \n",fd_two);
    write(fd_one,"Astrix", 6);
    write(fd_two," Ola mundo \n", 12);
    return(0);

}