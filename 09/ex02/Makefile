C++ = g++
C++FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = ./RPN
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:%.cpp=%.o)
INC = PmergeMe.hpp

all : $(NAME)

$(NAME):$(OBJS)
	$(C++) $(C++FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INC)
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
