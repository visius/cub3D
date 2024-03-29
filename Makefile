NAME = Cub3D.out

SRC =	cub3d.c parser.c parseres.c parsemap.c \
		dumpedfile.c raycast.c init.c draw.c utils.c \
		input.c sprite.c cubmove.c bmpsave.c errors.c

OBJ = ${SRC:.c=.o}

MLXLIB =	minilibx
CFLAGS =	-Ofast -march=native

MLX =	minilibx/libmlx.a
GL =	-lm -framework OpenGL -framework AppKit
CC =	gcc


all: lib
	$(CC) $(CFLAGS) $(SRC) $(MLX) $(GL) -o $(NAME)

run: all
	./$(NAME) maps/map.cub

lib:
	$(MAKE) -C $(MLXLIB)

clean:
	$(MAKE) clean -C $(MLXLIB)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
