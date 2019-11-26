# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bstacksp <bstacksp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 17:37:15 by bstacksp          #+#    #+#              #
#    Updated: 2019/11/26 20:00:59 by bstacksp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft
LIBFT_PATH = libft/libft.a
FILLIT = fillit

HEADERS = -I includes/
FLAGS = -Wall -Wextra -Werror

SRC_FOLDER = src
OBJ_FOLDER = obj

SRC_NAMES = main.c ft_read_input.c ft_validate_tetrimino.c tetr_solver.c tools.c

FILLIT_SRC = $(addprefix $(SRC_FOLDER)/, $(SRC_NAMES))

OBJ = $(addprefix $(OBJ_FOLDER)/, $(SRC_NAMES:.c=.o))

all: $(LIBFT_PATH) $(FILLIT)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(OBJ_FOLDER)
	@gcc -g $(FLAGS) $(HEADERS) -c $< -o $@
	@echo "Obj -> done"

$(LIBFT_PATH):
	@make -C $(LIBFT)
	@echo "Library -> done"

$(FILLIT): $(OBJ)
	@gcc -g $(OBJ) $(HEADERS) -L. $(LIBFT_PATH) -o $(FILLIT)
	@echo "FILLIT -> done"

clean:
	@make clean -C $(LIBFT)
	@/bin/rm -rf $(OBJ_FOLDER)
	@echo "Obj removed"

fclean: clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(FILLIT)
	@echo "Removed"

re: fclean all