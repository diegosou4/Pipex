# Pipex

## Visão Geral
Pipex é um projeto que tem como objetivo replicar o comportamento dos comandos executados pelos pipes no terminal. Isso é feito utilizando as funções pipe(), fork() e execv(). Através dessas funções, uma vez que temos o caminho do arquivo e os comandos a serem executados, precisamos criar um processo filho e então executar o execv(). Utilizando a função dup2(), podemos manipular onde nosso arquivo será lido e escrito, permitindo a comunicação entre os processos de forma eficiente.

## Resultado
![Resultado](https://i.imgur.com/Yd7GttY.png)

## Exemplo

![Exemplo](https://i.imgur.com/SPe2zFq.png)


## Instalação

Para executar o Pipex em sua máquina, siga estas etapas:

1. Clone o repositório:

   ```bash
   git clone https://github.com/diegosou4/Pipex
   cd Pipex
   make
   ./pipex file1 "cmd1" "cmd2" file2

