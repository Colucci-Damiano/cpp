
NAME	:= bureaucrat

SRCS	:=	Bureaucrat.cpp \
			AForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp \
			main.cpp \

OBJS	:= $(SRCS:.cpp=.o)

INC		:=	Bureaucrat.hpp \
			AForm.hpp \
			ShrubberyCreationForm.hpp \

CC		:= c++

CFLAGS	:= -Wall -Werror -Wextra

STD		:= -std=c++98

RM		:= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@ $(CC) $(CFLAGS) $(STD) $(OBJS) -o $(NAME)

%.o : %.cpp $(INC)
	@ $(CC) $(CFLAGS) $(STD) -c -o $@ $<

clean:
	@ $(RM) $(OBJS)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re