

#include <stdio.h>
#include <fcntl.h>

// O perror basicamente ele imprime o erro que o shell daria se voce fosse tentar fazer isso de forma manual
// Um exemplo disso e quando tentamos abrir o o file.txt e ele nao tem as permissoes para ser lido
// Entao ele nos retorna "Permission denied"

int main()
{
    int fd;

    fd = open("file.txt",O_RDONLY);
    if(fd == -1)
    {
        perror("Error");
        return(-1);
    }
    return(0);
}