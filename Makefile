# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okuznets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/20 13:10:06 by okuznets          #+#    #+#              #
#    Updated: 2018/10/20 13:10:06 by okuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INC = Includes

SDIR = Srcs

SRCS =
		main.c\

HEADERS = wolf3d.h

ODIR = Objects

OBJ = $(SRCS:.c=.o)

OBJ_R = $(OBJ:%.o=$(ODIR)/%.o)

all : $(NAME)

$(NAME) : $(ODIR)/ $(OBJ_R)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_R) ./libft/libft.a  -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

.PHONY: clean fclean re

clean :
	rm -f $(OBJ_R)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

norm:
	make norm -C libft
	norminette $(SRCS:%.c=$(SDIR)/%.c) $(HEADERS:%.h=$(INC)/%.h)

add:
	make add -C ./libft
	git add $(SRCS:%.c=$(SDIR)/%.c) $(HEADERS:%.h=$(INC)/%.h) .gitignore Makefile CMakeLists.txt author

test1: $(NAME)
	./$(NAME)

$(ODIR)/ :
	mkdir -p $@

$(ODIR)/%.o : $(SDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./libft -I $(INC)
