# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 18:12:02 by tlemma            #+#    #+#              #
#    Updated: 2021/12/23 03:02:56 by tlemma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

CC = clang
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=4 -g

RM = rm -f

AR = ar rs

SOURCES = ./src/push_swap.c \
			./src/sort.c \
			./src/stack_operations.c \
			./src/push.c \
			./src/utils.c \
			./src/simple_mid_sort.c \
			./src/sort_utils.c \
			./src/utils_2.c \
			./get_next_line/get_next_line_bonus.c \
			./get_next_line/get_next_line_utils_bonus.c

CHECKER_SRC = ./src/checker.c \
			./src/sort.c \
			./src/stack_operations.c \
			./src/push.c \
			./src/utils.c \
			./src/simple_mid_sort.c \
			./src/sort_utils.c \
			./src/utils_2.c \
			./get_next_line/get_next_line_bonus.c \
			./get_next_line/get_next_line_utils_bonus.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT = $(MAKE) -C ./libft

PRINTF = $(MAKE) -C ./ft_printf

$(NAME):
	$(LIBFT)
	$(PRINTF)
	$(CC) $(CFLAGS) $(SOURCES) ./libft/libft.a ./ft_printf/ft_printf.a -o $(NAME)

$(CHECKER):
	$(LIBFT)
	$(PRINTF)
	$(CC) $(CFLAGS) $(CHECKER_SRC) ./libft/libft.a ./ft_printf/ft_printf.a -o $(CHECKER)
	
all: $(NAME) $(CHECKER)

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./ft_printf clean
	$(RM) $(OBJECTS) 

fclean: clean
	$(RM) ./libft/libft.a
	$(RM) ./ft_printf/ft_printf.a
	$(RM) $(NAME) $(CHECKER)

re: fclean all
		
.PHONY: all clean fclean re bonus .c .o

.SILENT: