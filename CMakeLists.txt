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
set(SRC /Users/senglish/cub3d/srcs/)
set(LIB /Users/senglish/cub3d/libft/)

file(GLOB SRCS "${SRC}/*.c")
file(GLOB LIBFT "${LIB}/*.c")

add_executable(cub3d ${SRCS} ${LIBFT})