
NAME	:=	character

SRCS	:=	AMateria.cpp \
			Cure.cpp \
			Ice.cpp \
			Character.cpp \
			main.cpp \


OBJS	:=	$(SRCS:.cpp=.o)

CC		:=	c++

CFLAGS	:=	-Wall -Werror -Wextra -g

STD		:=	-std=c++98

INC		:=	AMateria.hpp \
			Cure.hpp \
			Ice.hpp \
			ICharacter.hpp \
			Character.hpp \
			IMateriaSource.hpp \
			MateriaSource.hpp \

RM		:=	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(CFLAGS) $(STD) $(OBJS) -o $(NAME)

%.o: %.cpp $(INC)
	 $(CC) $(CFLAGS) $(STD) -c -o $@ $<

clean:
	@ $(RM) $(OBJS)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
