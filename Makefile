NAME	=	cub3D

INCL	=	includes

MAKE	=	make

OBJ_DIR	=	.obj

LIB		=	libft/libft.a

SRCS_DIR=	srcs

SRCS	=	$(SRCS_DIR)/error.c	$(SRCS_DIR)/ident.c	$(SRCS_DIR)/init.c\
			$(SRCS_DIR)/main.c $(SRCS_DIR)/map.c	$(SRCS_DIR)/parse.c

#B_DIR	=	$(B_DIR)/
#
#BONUS	=

OBJS	= 	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

BOBJS	=	$(addprefix) $(OBJ_DIR)/,$(BONUS:.c=.o))

CFLAGS	=	-g -Wall -Wextra -Werror -I $(INCL) -Imlx

CC		=	gcc

RM		=	rm -f

HEADER	=	$(INCL)/cub3D.h

.PHONY	:	all bonus clean fclean re

$(OBJ_DIR)/%.o:%.c $(HEADER)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(SRCS_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

all		:	$(NAME)

bonus	:	$(BOBJS)
				$(MAKE) -C $(dir $(LIB))
				$(CC) $(CFLAGS) $(BOBJS) $(LIB) -o $(NAME)

$(NAME)	:	$(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB)	:
	$(MAKE) -C ./libft

%.o : %.c $(HEADER) $(BHEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	$(MAKE) clean -C ./libft/
	$(RM) -rf $(OBJ_DIR)

fclean	:	clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re		: fclean all
