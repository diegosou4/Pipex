NAME = pipex

PRINTF_SRC = ft_printc.c ft_printf.c ft_putstr.c ft_strrchr.c \
	     ft_hexdec.c ft_putchar.c ft_putnbr.c ft_strlen.c \
		 ft_printp.c ft_unsigned.c  

LIBFT_SRC = ft_strnstr.c

PIPEX_SRC = ft_getenv.c


SRCL = $(addprefix ./src/libft/, $(LIBFT_SRC))
SRCP = $(addprefix ./src/ft_printf/, $(PRINTF_SRC))
SRCPX = $(addprefix ./src/pipex/, $(PIPEX_SRC))
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes


all:
	${CC} main.c ${SRCL} ${SRCPX} ${SRCP} -o ${NAME} 
