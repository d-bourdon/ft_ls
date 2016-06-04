# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/30 15:44:04 by dbourdon          #+#    #+#              #
#*   Updated: 2016/06/04 10:35:13 by dbourdon         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = *.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: clean fclean re libft

all: $(NAME)

$(NAME) : libft
	@clang $(FLAGS) $(SRC) -g -o $(NAME) -L./libft/ -lft
	@echo "Compilation"

libft:
	@make -C libft/

clean: 
	@make -C libft/ clean
	@rm -f $(OBJ) *.gch
	@echo "Supression"

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "totale..."

re: fclean all
	@make re -C libft/
