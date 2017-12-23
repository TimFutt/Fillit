#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/11/13 18:12:06 by cbaillat          #+#    #+#             *#
#*   Updated: 2017/11/14 18:28:12 by cbaillat         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fillit

SRC = srcs/algorithm.c \
	  srcs/input.c \
	  srcs/main.c \
	  srcs/map.c \
	  srcs/output.c \
	  srcs/utils_input.c

OBJ = algorithm.o \
	  input.o \
	  main.o \
	  map.o \
	  output.o \
	  utils_input.o \

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
		make -C ./libft/
		gcc -c $(FLAGS) $(SRC)
		gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

clean :
	rm -rf $(OBJ)
	make clean -C ./libft/

fclean : clean
	make fclean -C ./libft/
	rm -rf $(NAME)

re : fclean all
