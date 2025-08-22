NAME = replace
CC = c++ 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
RM = rm -rf

SRCS = main.cpp\

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS)  $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: re all clean fclean