# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 14:58:57 by mle-biha          #+#    #+#              #
#    Updated: 2023/01/17 17:06:02 by mle-biha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -I. -g
SRC     = ft_atoi.c \
			libft.c \
			main.c \
			push_swap_utils.c \
			push_swap.c \
			quick_sort.c \
			stack_moves_utils.c \
			stack_utils.c \
			stack.c \

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re
