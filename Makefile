# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/30 15:44:04 by dbourdon          #+#    #+#              #
#    Updated: 2016/04/30 15:48:51 by dbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c\
	  ft_erreur.c\
	  ft_lecture_option.c\
	  ft_detection_option.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: clean fclean re libft

all: $(NAME)

$(NAME) : libft
	@clang $(FLAGS) $(SRC) -o $(NAME) -L./libft/ -lft
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
