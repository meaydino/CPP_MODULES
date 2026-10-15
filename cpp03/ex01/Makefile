NAME =	ClapTrap
SRC =	main.cpp ClapTrap.cpp ScavTrap.cpp
CXX = c++

OBJ = $(SRC:.cpp=.o)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re