# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/17 16:08:20 by pdavid            #+#    #+#              #
#    Updated: 2018/05/21 18:10:50 by pdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libx_flags = -L minilibx -lmlx -framework OpenGL -framework AppKit

cflags = -Wall -Wextra -Werror -lpthread

make_libft = @make -C ./libft/

header = fractol.h

includes = ./libft/libft.a ./minilibx/libmlx.a

SRC = tools.c mandel.c main.c key.c init.c julia.c

OBJ = *.o

cc = @gcc

name = fractol

all : $(name)

$(name) :
	@make -C libft/
	$(cc) $(libx_flags) $(SRC) $(includes) -o $(name)
	@echo "Created Fractol executable"
	
clean:
	@make -C libft/ clean
	@/bin/rm -f $(name)
	
fclean: clean
	@make -C libft/ fclean
	
re: fclean all