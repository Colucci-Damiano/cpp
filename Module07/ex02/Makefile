
NAME	:=	array

SRCS	:=	main.cpp \

OBJS	:=	$(SRCS:.cpp=.o)

INC		:=	Array.hpp \

CC		:= c++
CFLAGS	:= -Wall -Werror -Wextra -g
STD		:= -std=c++98

%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) $(STD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(STD) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
