#include<stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 


// Dup cria um novo fd porem esse fd aponta para o outro
// Por mais que o numero do fd seja diferente ele quando
// vai escrever algo ele escreve no primeiro

int main()
{
    int fd_one;

    fd_one = open("file.txt", O_WRONLY | O_APPEND);

    int fd_two;

    fd_two = dup(fd_one);

    printf("%i fd_one \n",fd_one);
    printf("%i fd_two \n",fd_two);
    write(fd_one,"Astrix", 6);
    write(fd_two," Ola mundo \n", 12);
    return(0);
}