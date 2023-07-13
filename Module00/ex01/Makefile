NAME := phonebook

SRCS := main.cpp Contact.cpp PhoneBook.cpp

OBJS := $(SRCS:.cpp=.o)

CC := g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@ $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@ $(CC) $(CFLAGS) -c -o $@ $<

clean:
	@ rm -rf $(OBJS)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
