
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = Fractal


SFILES = main.c utils.c render.c events.c
OFILES = $(SFILES:.c=.o)

all:$(NAME)
	$CC $CFLAGS SFILES -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)

$(NAME):
	