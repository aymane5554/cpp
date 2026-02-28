C++ = c++
C++FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = exe
SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:%.cpp=%.o)
INC = Bureaucrat.hpp

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
