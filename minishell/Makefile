# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 16:34:55 by juan-ant          #+#    #+#              #
#    Updated: 2024/12/16 16:05:45 by juan-ant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -g

BONUS_NAME =

NAME = minishell

FILES = patch/main.c patch/shell_preparation.c list/lstcontrol.c list/lstcontrol_2.c aux/free_mem.c tokens/maintoken.c tokens/special_chars/singlequotes.c tokens/special_chars/doublequotes.c tokens/special_chars/handleplain.c

OBJ = $(FILES:%.c=%.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(MAKE) -C libft
	cc $(FLAGS) -lreadline $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ): %.o:%.c
	clang -c $(FLAGS) $^ -o $@

$(LIBFT):
	$(MAKE) -C libft

$(BON_OBJ): %.o:%.c
	clang -c $(FLAGS) $^ -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: clean
.PHONY: fclean
.PHONY: re
.PHONY: all
