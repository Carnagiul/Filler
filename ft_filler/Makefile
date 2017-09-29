# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piquerue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/19 05:33:28 by piquerue          #+#    #+#              #
#    Updated: 2017/05/19 05:33:29 by piquerue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_filler.a

SRC = $(shell find . -type f | grep "\.c")

OBJ = ft_filler_algo.o
OBJ += ft_filler_check.o
OBJ += ft_filler_core.o
OBJ += ft_filler_data.o
OBJ += ft_filler_piece.o

OBJ_2 = obj/ft_filler_algo.o
OBJ_2 += obj/ft_filler_check.o
OBJ_2 += obj/ft_filler_core.o
OBJ_2 += obj/ft_filler_data.o
OBJ_2 += obj/ft_filler_piece.o

INCLUDE = $(shell find ../ -type f | grep "\.h")

obj/%.o: %.c
	mkdir -p obj/
	gcc -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJ_2)
	gcc -c -Wall -Werror -Wextra $(SRC) -I ../
	ar rc $(NAME) $(OBJ)
	mv $(OBJ) obj/
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ_2)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
