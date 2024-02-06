NAME = pipex

PRINTF_SRC = ft_printc.c ft_printf.c ft_putstr.c ft_strrchr.c \
	     ft_hexdec.c ft_putchar.c ft_putnbr.c ft_strlen.c \
		 ft_printp.c ft_unsigned.c  

SRCP = $(addprefix ./src/, $(PRINTF_SRC))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes


all:
	${CC} main.c ${SRCP} -o ${NAME} 
