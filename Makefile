NAME = pipex

BOLD = \033[1m
RESET = \033[0m
BLUE = \033[34m
RED = \033[31m

PRINTF_SRC = ft_printc.c ft_printf.c ft_putstr.c ft_strrchr.c \
	     ft_hexdec.c ft_putchar.c ft_putnbr.c ft_printp.c  \
		 ft_unsigned.c  

LIBFT_SRC = ft_strnstr.c ft_calloc.c ft_bzero.c ft_split.c \
			ft_strlen.c ft_strdup.c ft_strjoin.c ft_substr.c \
			ft_strcmp.c

PIPEX_SRC = ft_getenv.c checkpath.c utils.c exec.c \
			acess.c open.c mysplit.c free_struct.c

SRCOBJ = obj/

SRC = $(addprefix ./src/libft/, $(LIBFT_SRC)) \
		$(addprefix ./src/ft_printf/, $(PRINTF_SRC)) \
	 	$(addprefix ./src/pipex/, $(PIPEX_SRC))

OBJ = $(addprefix $(SRCOBJ), $(SRC:./src/%.c=%.o))
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes

all: $(NAME)
$(NAME): $(OBJ)
	@echo "$(BOLD)$(BLUE)$(NAME) has been compiled successfully!$(RESET)"
	@${CC} ${CFLAGS} -g pipex.c ${OBJ} -o $(NAME) 

$(SRCOBJ)%.o: src/%.c
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@
clean:
	@echo "$(BOLD)$(RED)Cleaning up objects files!$(RESET)"
	@rm -rf $(SRCOBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all