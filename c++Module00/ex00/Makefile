NAME := megaphone
CC := c++

SRC := megaphone.cpp

OBJ := megaphone.o

CFLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@ rm -rf $(NAME)
fclean: clean
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re