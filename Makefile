# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bstacksp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 17:37:15 by bstacksp          #+#    #+#              #
#    Updated: 2019/10/04 17:45:33 by bstacksp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADERS = fillit.h

SOURCE = fillit.c

OBJECTS = fillit.o

all: $(NAME)
	gcc -I $(HEADERS) -Wall -Werror -Wextra $< -c -o $(NAME)

clean: 
	rm -f $(OBJECTS)

fclean: 
	rm -f $(NAME)

re:
	fclean all
