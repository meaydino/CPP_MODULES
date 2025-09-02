NAME =	phonebook
SRC =	src/main.cpp src/PhoneBook.cpp src/Contact.cpp
SRCDIR = src/
INCDIR = include/
CXX = c++

OBJ = $(SRC:.cpp=.o)
FLAG = -Wall -Wextra -Werror -std=c++98 -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAG) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
