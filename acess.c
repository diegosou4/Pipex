
#include <unistd.h>
#include <stdio.h>

/// Acess ele verifica se podemos simplesmente podemos fazer algo com aquele arquivo
// Como ler, escrever ou editar
// Ele retorna 0 quando deu certo
// Ele retorna -1 caso nao consiga fazer aquela solicitacao


int main()
{

    char *path = "file.txt";
    int i;

    i = access(path,R_OK);

    printf("%i \n", i);

    return(0);
}