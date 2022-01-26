NAME	=	cub3D

INCL	=	includes

MAKE	=	make

OBJ_DIR	=	.obj

LIB		=	./libft/libft.a

#LIBMLX	=	./mlx/libmlx.a

SRCS_DIR=	srcs

SRCS	=	$(SRCS_DIR)/dbg.c			$(SRCS_DIR)/draw.c	$(SRCS_DIR)/error.c\
			$(SRCS_DIR)/ident.c	$(SRCS_DIR)/init.c\
			$(SRCS_DIR)/key_handler.c	$(SRCS_DIR)/main.c 	$(SRCS_DIR)/map.c\
			$(SRCS_DIR)/parse.c			$(SRCS_DIR)/ray.c	$(SRCS_DIR)/rgb.c\
			$(SRCS_DIR)/vectors.c

#B_DIR	=	$(B_DIR)/
#
#BONUS	=

OBJS	= 	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

BOBJS	=	$(addprefix) $(OBJ_DIR)/,$(BONUS:.c=.o))

CFLAGS	=	-g -Wall -Wextra -Werror -I $(INCL) -Imlx

CC		=	clang

MLX		=	-lmlx -L./mlx/ -framework OpenGL -framework AppKit

RM		=	rm -f

HEADER	=	$(INCL)/cub3D.h

.PHONY	:	all bonus clean fclean re

$(OBJ_DIR)/%.o:%.c $(HEADER)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(SRCS_DIR)
	$(CC) -c $(CFLAGS) -o $@ $<

all		:	$(NAME)

bonus	:	$(BOBJS)
				$(MAKE) -C $(dir $(LIB))
				$(CC) $(CFLAGS) $(BOBJS) $(LIB) $(MLX) -o $(NAME)

$(NAME)	:	$(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) ./libft/libft.a $(MLX) -o $(NAME)

$(LIB)	:
	$(MAKE) -C ./libft

#$(LIBMLX):
#	$(MAKE) -C ./mlx

%.o : %.c $(HEADER) $(BHEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	$(MAKE) clean -C ./libft/
#	$(MAKE) clean -C ./mlx/
	$(RM) -rf $(OBJ_DIR)

fclean	:	clean
	$(MAKE) fclean -C ./libft
#	$(MAKE) fclean -C ./mlx
	$(RM) $(NAME)

re		: fclean all
