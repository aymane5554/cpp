C++FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = exe
SRCS = main.cpp ScalarConverter.cpp
OBJS = $(SRCS:%.cpp=%.o)
INC = ScalarConverter.hpp

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
