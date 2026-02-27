C++FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = exe
SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJS = $(SRCS:%.cpp=%.o)
INC = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

all : $(NAME)

$(NAME):$(OBJS)
	c++ $(C++FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INC)
	c++ $(C++FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
