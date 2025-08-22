

CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	fixed
FILES	=	main.cpp Fixed.cpp
TEST	=	my.txt

OBJ		=	$(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJ) $(wildcard *.gch)

fclean: clean
	$(RM) $(NAME) $(TEST)

re: fclean all

test: $(NAME)
	./$< > $(TEST)
	diff $(TEST) expected.txt
