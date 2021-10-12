# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 12:01:15 by mbueno-g          #+#    #+#              #
#    Updated: 2021/10/12 13:25:51 by mbueno-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc 
FLAGS = -Wall -Werror -Wextra #-lpthread
RM = rm -f

SRC_M = main.c utils_libft.c utils.c

OBJ_M = $(SRC_M:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ_M)
		$(CC) $(FLAGS) $(OBJ_M) -o $@

$(OBJ_M): $(SRC_M)
		$(CC) $(FLAGS) -c $^

clean: 
		$(RM) $(OBJ_M) 

fclean: clean
		$(RM) $(LIBFT)
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
