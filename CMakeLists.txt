cmake_minimum_required(VERSION 3.14)
project(fdf C)

set(CMAKE_C_STANDARD 99)

file(GLOB C_HEADERS "minilibx_macos/*.h")

add_definitions(-Wall -Werror -Wextra)
#add_compile_options(-Wall -Wextra -Werror)

#target_link_libraries(fdf
#        LINK_PUBLIC ${CMAKE_SOURCE_DIR}/libft/libft.a)

add_executable(fdf main.c fdf.h
        libft/ft_memset.c
        libft/ft_bzero.c
        libft/ft_memcpy.c
        libft/ft_memccpy.c
        libft/ft_memmove.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_strlen.c
        libft/ft_strdup.c
        libft/ft_strcpy.c
        libft/ft_strncpy.c
        libft/ft_strcat.c
        libft/ft_strncat.c
        libft/ft_strlcat.c
        libft/ft_strchr.c
        libft/ft_strrchr.c
        libft/ft_strstr.c
        libft/ft_strnstr.c
        libft/ft_strcmp.c
        libft/ft_strncmp.c
        libft/ft_atoi.c
        libft/ft_atoi_base.c
        libft/ft_isalpha.c
        libft/ft_isdigit.c
        libft/ft_isalnum.c
        libft/ft_isascii.c
        libft/ft_isprint.c
        libft/ft_toupper.c
        libft/ft_tolower.c
        libft/ft_memalloc.c
        libft/ft_memdel.c
        libft/ft_strnew.c
        libft/ft_strdel.c
        libft/ft_strclr.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strequ.c
        libft/ft_strnequ.c
        libft/ft_strsub.c
        libft/ft_strjoin.c
        libft/ft_strtrim.c
        libft/ft_strsplit.c
        libft/ft_itoa.c
        libft/ft_pow.c
        libft/ft_putchar.c
        libft/ft_putstr.c
        libft/ft_putendl.c
        libft/ft_putnbr.c
        libft/ft_putchar_fd.c
        libft/ft_putstr_fd.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr_fd.c
        libft/ft_lstnew.c
        libft/ft_lstdelone.c
        libft/ft_lstdel.c
        libft/ft_lstadd.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_charcount.c
        libft/ft_wordcount.c
        libft/ft_strfree.c
        libft/ft_intcount.c
        libft/ft_isupper.c
        libft/ft_islower.c
        libft/ft_isspace.c
        libft/ft_lstlen.c
        libft/ft_del.c
        libft/ft_degtorad.c
        libft/ft_map_char.c
        libft/ft_map_int.c
        libft/ft_map_void.c
        libft/ft_put_map_int_fd.c
        libft/ft_put_map_chr_fd.c
        libft/ft_map_int_del.c
        libft/ft_map_chr_del.c
        libft/ft_map_void_del.c
        libft/ft_str_rejoin.c
        libft/ft_radtodeg.c
        libft/libft.h
        get_next_line/get_next_line.c
        get_next_line/get_next_line.h
        put_line.c input_map.c fdf.c draw_grid.c initialization.c calculation.c info.c validation.c put_map_point_fd.c hook_deal_key.c)

target_link_libraries(${PROJECT_NAME}
        "mlx"
        "-framework OpenGL"
        "-framework AppKit")
