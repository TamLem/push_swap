# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 18:12:02 by tlemma            #+#    #+#              #
#    Updated: 2021/12/22 19:32:31 by tlemma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
RM = rm -f

AR = ar rs

SOURCES = ft_printf.c ft_put.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) 
	$(AR) $(NAME) $(OBJECTS) 

all: $(NAME)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
		
.PHONY: all clean fclean re bonus .c .o