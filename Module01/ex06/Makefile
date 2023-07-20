
NAME := harlFilter

SRCS :=	main.cpp \
		Harl.cpp \

OBJS := $(SRCS:.cpp=.o)

CC := c++
CFLAGS := -Wall -Werror -Wextra

INC :=	Harl.hpp \

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
