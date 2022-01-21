cmake_minimum_required(VERSION 3.20)
project(cub3d C)

include_directories("/Users/senglish/cub3d/includes/")
include_directories("/Users/senglish/cub3d/mlx/")
include_directories("/Users/senglish/cub3d/libft/")
include_directories("/Users/senglish/cub3d/srcs/")
include_directories("/Users/senglish/cub3d/.obj/")

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -gdwarf-3")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-3")

set(SRCS srcs/main.c srcs/error.c srcs/parse.c)
set(LIBFT libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_itoa.c
        libft/ft_isprint.c libft/ft_isdigit.c libft/ft_isascii.c libft/ft_isalnum.c
        libft/ft_isalpha.c libft/ft_memcpy.c libft/ft_memchr.c libft/ft_memset.c
        libft/ft_memmove.c libft/ft_memmove.c libft/ft_memcmp.c libft/ft_putstrlen_fd.c
        libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_putendl_fd.c
        libft/ft_putcharlen_fd.c libft/ft_putchar_fd.c libft/ft_substr.c
        libft/ft_strrchr.c libft/ft_strmapi.c libft/ft_strtrim.c libft/ft_strchr.c
        libft/ft_split.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c
        libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strnstr.c
        libft/ft_toupper.c libft/ft_tolower.c)


add_executable(cub3d ${SRCS} ${LIBFT})