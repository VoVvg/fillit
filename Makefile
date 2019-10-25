# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 17:37:15 by bstacksp          #+#    #+#              #
#    Updated: 2019/10/20 18:25:23 by bstacksp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADERS = fillit.h

SOURCE = main.c

OBJECTS = main.o

all: $(NAME)
	gcc -I $(HEADERS) -Wall -Werror -Wextra $< -c -o $(NAME)

clean: 
	rm -f $(OBJECTS)

fclean: 
	rm -f $(NAME)

re:
	fclean all
