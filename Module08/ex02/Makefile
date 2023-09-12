
NAME	:=	mutantStack

SRCS	:=	main.cpp \

OBJS	:= $(SRCS:.cpp=.o)

INC		:=	MutantStack.hpp \

CC		:=	c++
CFLAGS	:=	-Wall -Werror -Wextra
STD		:=	-std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(STD) $< -o $@

%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) $(STD) -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re