NAME	=	cub3D

INCL	=	includes

OBJ_DIR	=	.obj

LIB		=	libft/libft.a

SRCS_DIR=	srcs

SRCS	=	$(SRCS_DIR)/main.c

#B_DIR	=	$(B_DIR)/
#
#BONUS	=

OBJS	= 	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

BOBJS	=	$(addprefix) $(OBJ_DIR)/,$(BONUS:.c=.o))

CFLAGS	=	-g -Wall -Wextra -Werror -I $(INCL) -Imlx

CC		=	gcc

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
	$(MAKE) clean -C ./libft

fclean	:	clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re		: fclean all