NAME=RPN
CXX=c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98  
RM=rm -rf

SRCS = main.cpp RPN.cpp

OBJS=$(SRCS:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY:re all fclean clean