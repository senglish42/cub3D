NAME	=	libft.a

CC		=	gcc

INCL	=	../includes

CFLAGS	=	-Wall -Wextra -Werror -I $(INCL)

RM		=	rm -f

SRC		=	ft_memset.c		ft_bzero.c		ft_memcpy.c \
			ft_memccpy.c	ft_memmove.c	ft_memchr.c \
			ft_memcmp.c		ft_strlen.c		ft_strlcpy.c \
			ft_strlcat.c	ft_strchr.c		ft_strrchr.c \
			ft_strnstr.c	ft_strncmp.c	ft_atoi.c \
			ft_isalpha.c	ft_isdigit.c	ft_isalnum.c \
			ft_isascii.c	ft_isprint.c	ft_toupper.c \
			ft_tolower.c	ft_calloc.c 	ft_putnbr_fd.c\
			ft_putendl_fd.c	ft_putstr_fd.c	ft_putchar_fd.c\
			ft_strmapi.c	ft_substr.c		ft_strjoin.c\
			ft_strtrim.c	ft_strdup.c		ft_strtrim.c\
			ft_itoa.c		ft_split.c		ft_putcharlen_fd.c\
			ft_putstrlen_fd.c

OBJ		=	$(patsubst %.c,%.o,$(SRC))

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@ar rsc $(NAME) $?

%.o		: 	%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	@$(RM) $(OBJ)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all
