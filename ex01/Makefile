NAME     = phonebook
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp contact.cpp phonebook.cpp
OBJS = $(SRCS:.cpp=.o)
HDRS = contact.hpp phonebook.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re