NAME = account
CC = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCS = tests.cpp\
		Account.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: re all clean fclean