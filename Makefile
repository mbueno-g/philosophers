

NAME = philo
CC = gcc 
FLAGS = -Wall -Werror -Wextra -lpthread
RM = rm -f

SRC_M = main.c utils_libft.c

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
