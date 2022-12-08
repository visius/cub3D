SRC =	cub3d.c \
		parser.c \
		parseres.c \
		parsemap.c \
		parsemap2.c \
		dumpedfile.c \
		raycast.c \
		raycast2.c \
		init.c \
		draw.c \
		utils.c \
		utils2.c \
		input.c \
		sprite.c \
		cubmove.c \
		bmpsave.c \
		errors.c

NAME = cub3D

CC = gcc

OBJS	= ${SRC:.c=.o}

LIB_MLX 	= minilibx_mms_20200219
MLXLIBA		= $(LIB_MLX)/libmlx.dylib

COPY_FILES = cp -f $@ $(MLXLIBA)

INCLUDES = -I$(LIB_MLX)

CFLAGS	= -Wall -Werror -Wextra -g
CFLAGS		=	-Ofast -march=native
MLXFLAGS	=	-framework OpenGL \
				-framework AppKit \
				-fsanitize=address

all:		$(NAME)

$(NAME):	$(MLXLIBA) $(OBJS)
			cp minilibx_mms_20200219/libmlx.dylib .
			$(CC) $(CFLAGS) $(MLXLIBA) $(OBJS) $(MLXFLAGS) -o $(NAME)

	
$(MLXLIBA):		
			$(MAKE) -C $(LIB_MLX)

clean:
		rm -rf $(OBJS)
		$(MAKE) clean -C $(LIB_MLX)

re:			fclean all
