
NAME	:=	PmergeMe

#Sources
SRCS	:=	main.cpp \
			PmergeMe.cpp \

OBJS	:=	$(SRCS:.cpp=.o)

HEADERS	:=	PmergeMe.hpp \

#Compiler
CC		:=	c++
CFLAGS	:=	-Wall -Werror -Wextra
STD		:=	-std=c++98

RM		:=	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(STD) $(OBJS) -o $@
	@echo "\033[32mCompiled ✅"

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(STD) $< -c

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
