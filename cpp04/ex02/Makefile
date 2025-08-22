

NAME	= animal
SRC_DIR	= src/
INC_DIR	= inc/
SRC		= $(SRC_DIR)main.cpp \
			$(SRC_DIR)Animal.cpp \
			$(SRC_DIR)Dog.cpp \
			$(SRC_DIR)Cat.cpp \
			$(SRC_DIR)Brain.cpp
OBJ		= $(SRC:.cpp=.o)
CXX		= c++
CFL		= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFL) -I $(INC_DIR) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CFL) -I $(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
