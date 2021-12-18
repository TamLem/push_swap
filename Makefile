# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 18:12:02 by tlemma            #+#    #+#              #
#    Updated: 2021/12/18 20:27:41 by tlemma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

CC = gcc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=4

RM = rm -f

AR = ar rs

SOURCES = ./src/push_swap.c \
			./src/sort.c \
			./src/stack_operations.c \
			./src/utils.c \
			./get_next_line/get_next_line_bonus.c \
			./get_next_line/get_next_line_utils_bonus.c

CHECKER_SRC = ./src/checker.c \
			./src/sort.c \
			./src/stack_operations.c \
			./src/utils.c \
			./get_next_line/get_next_line_bonus.c \
			./get_next_line/get_next_line_utils_bonus.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT = $(MAKE) -C ./libft

$(NAME):
	$(LIBFT)
	$(CC) $(CFLAGS) $(SOURCES) ./libft/libft.a -o $(NAME)

$(CHECKER):
	$(LIBFT)
	$(CC) $(CFLAGS) $(CHECKER_SRC) ./libft/libft.a -o $(CHECKER)
	
all: $(NAME)

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJECTS) 

fclean: clean
	$(RM) ./libft/libft.a
	$(RM) $(NAME) $(CHECKER)

re: fclean all
		
.PHONY: all clean fclean re bonus .c .o