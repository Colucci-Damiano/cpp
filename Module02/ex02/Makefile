
NAME := fixed

SRCS :=	main.cpp \
		Fixed.cpp \

OBJS := $(SRCS:.cpp=.o)

INC := Fixed.hpp \

CFLAGS := -Wall -Werror -Wextra
CC := c++

STD := -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@ $(CC) $(CFLAGS) $(STD) $(OBJS) -o $(NAME)

%.o: %.cpp $(INC)
	@ $(CC) $(CFLAGS) $(STD) -c -o $@ $<

clean:
	@ rm -rf $(OBJS)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
