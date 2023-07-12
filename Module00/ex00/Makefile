NAME := megaphone
CC := c++

SRC := megaphone.cpp

OBJ := megaphone.o

CFLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	@ $(CC) $(CFLAGS) $(SRC) -c $<

clean:
	@ rm -rf $(OBJ)
fclean: clean
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
