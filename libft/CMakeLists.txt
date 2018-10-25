cmake_minimum_required(VERSION 3.9)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(NAME libft.a)
project(${NAME} C)
set(LIBFT_INC ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

set(SOURCES
		"ft_abs.c"
		"ft_count_letters.c"
		"ft_count_word.c"
		"ft_is_delimeter.c"
		"ft_isalnum.c"
		"ft_isalpha.c"
		"ft_isascii.c"
		"ft_isprint.c"
		"ft_isdigit.c"
		"ft_atoi.c"
		"ft_itoa.c"
		"ft_bzero.c"
		"ft_lst_push_back.c"
		"ft_lstadd.c"
		"ft_lstdel.c"
		"ft_lstdelone.c"
		"ft_lstiter.c"
		"ft_lstmap.c"
		"ft_lstnew.c"
		"ft_memalloc.c"
		"ft_memccpy.c"
		"ft_memchr.c"
		"ft_memcmp.c"
		"ft_memcpy.c"
		"ft_memdel.c"
		"ft_memmove.c"
		"ft_memset.c"
		"ft_putchar.c"
		"ft_putchar_fd.c"
		"ft_putendl.c"
		"ft_putendl_fd.c"
		"ft_putnbr.c"
		"ft_putnbr_fd.c"
		"ft_putstr.c"
		"ft_putstr_fd.c"
		"ft_putstr_till.c"
		"ft_strcat.c"
		"ft_strclr.c"
		"ft_strcmp.c"
		"ft_strclr.c"
		"ft_strcpy.c"
		"ft_strdel.c"
		"ft_strdup.c"
		"ft_strequ.c"
		"ft_striter.c"
		"ft_striteri.c"
		"ft_strjoin.c"
		"ft_strlcat.c"
		"ft_strlen.c"
		"ft_strmap.c"
		"ft_strmapi.c"
		"ft_strncat.c"
		"ft_strncmp.c"
		"ft_strncpy.c"
		"ft_strnequ.c"
		"ft_strnew.c"
		"ft_strnstr.c"
		"ft_strrchr.c"
		"ft_strrev.c"
		"ft_strsplit.c"
		"ft_strstr.c"
		"ft_strsub.c"
		"ft_strtrim.c"
		"ft_tolower.c"
		"ft_toupper.c"
		"ft_strchr.c"
		"ft_strcpy.c"
		"ft_strdup.c"
		"ft_strsub.c"
		"ft_strjoin.c"
		"ft_strsplit.c"
		"ft_memcmp.c"
		"ft_memset.c"
		"get_next_line.c")

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR} CACHE PATH "Executable output dir" FORCE)
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/ft_printf)
add_library(${NAME} ${SOURCES})
