NAME= arrar
CXX= c++
CXXFLAGS= -Wextra -Wall -Werror -std=c++98
RM=rm -rf

SRCS = main.cpp #main_1.cpp 

OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY:re all fclean clean
