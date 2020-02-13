# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 17:37:15 by bstacksp          #+#    #+#              #
#    Updated: 2019/12/01 18:06:54 by bstacksp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADERS = -I includes/
FLAGS = -Wall -Wextra -Werror

SRC_FOLDER = src
OBJ_FOLDER = obj

SRC_NAMES = main.c ft_read_input.c ft_validate_tetrimino.c tetr_solver.c

FILLIT_SRC = $(addprefix $(SRC_FOLDER)/, $(SRC_NAMES))

OBJ = $(addprefix $(OBJ_FOLDER)/, $(SRC_NAMES:.c=.o))

all: $(NAME)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(OBJ_FOLDER)
	@gcc -g $(FLAGS) $(HEADERS) -c $< -o $@
	@echo "Obj -> done"

$(NAME): $(OBJ)
	@gcc -g $(OBJ) $(HEADERS) -o $(NAME)
	@echo "FILLIT -> done"

clean:
	@/bin/rm -rf $(OBJ_FOLDER)
	@echo "Obj removed"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Files removed"

re: fclean all
