NAME=myAwesomePhoneBook
CC=c++
CXXFLAGS=-Wextra -Wall -Werror -std=c++98
RM=rm -rf

SRCS = main.cpp\
		Contact.cpp\
		PhoneBook.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
