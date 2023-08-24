NAME	:= identify

SRCS	:=	main.cpp \
			Classes.cpp \

OBJS	:=	$(SRCS:.cpp=.o)

INC		:=  Classes.hpp \

CC		:= c++
CFLAGS	:= -Wall -Werror -Wextra
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