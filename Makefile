
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol


SFILES = main.c utils.c render.c events.c
OFILES = $(SFILES:.c=.o)

all:$(NAME)

${NAME}: ${OFILES}
	${CC} ${CFLAGS} ${OFILES} -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o ${NAME}

clean: 
	rm -f ${OFILES}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re