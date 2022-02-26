
#LINUX_VERSION
#cmake_minimum_required(VERSION 3.20)
#project(cub3d C)
#
cmake_minimum_required(VERSION 3.20)
project(cub3d C)

include_directories("includes")
include_directories("minilibx_linux")
include_directories("libft")
include_directories("srcs")
include_directories(".obj")

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Imlx -lmlx -L/mlx/ -framework OpenGL
#-framework AppKit")
#set(CMAKE_C_STANDARD 99)
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -gdwarf-3")
#set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-3")
set(SRC srcs)
set(LIB libft)

file(GLOB SRCS "${SRC}/*.c")
file(GLOB LIBFT "${LIB}/*.c")
#
#
#set(CMAKE_C_STANDARD 99)
#
#set(libmlx.a libname)
#target_link_libraries(libmlx.a Qt5::Widgets Qt5::Core)

#target_link_libraries(cub3d
#        /home/senglish/projects/cub3D/minilibx_linux/libmlx_Linux.a
#        "-lXext"
#        "-lX11"
#        "-lm"
#        )

#target_link_libraries(cub3d
#        /Users/senglish/projects/cub3D/mlx/libmlx.a
#        "-framework OpenGL"
#        "-framework AppKit"
#        )

add_executable(cub3d ${SRCS} ${LIBFT})
