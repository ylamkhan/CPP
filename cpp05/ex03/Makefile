

C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
INFILES = 	main.cpp\
			Bureaucrat.cpp\
			AForm.cpp\
			ShrubberyCreationForm.cpp\
			RobotomyRequestForm.cpp\
			PresidentialPardonForm.cpp\
			Intern.cpp\

OBJFILES = $(INFILES:.cpp=.o)

NAME = At_least_this_beats_coffee-making

all: $(NAME)

$(NAME):$(OBJFILES)
	$(C++) $(C++_FLAGS) $(OBJFILES) -o $(NAME) 

%.o: %.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re