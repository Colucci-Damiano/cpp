
NAME := bank

SRCS := tests.cpp Account.cpp

OBJS := $(SRCS:.cpp=.o)

CC := c++
CFLAGS := -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@ $(CC) $(CFLAGS) $(OBJS) -o $<

%.o: %.cpp
	@ $(CC) $(CFLAGS) -c -o $@ $<

clean:
	@ rm -rf $(OBJS)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
