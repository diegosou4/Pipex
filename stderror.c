#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

//  A diferenca e que strerror eu posso guardar o erro e posso fazer o que eu quiser com ele
// O perror so vai imprimir na tela
int main()
{
    int fd;

    fd = open("file.txt",O_RDONLY);

    if(fd == -1)
    {
         printf("Error: %s\n", strerror(errno));
    }
    return(0);

}