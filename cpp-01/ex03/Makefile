CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra
NAME		=	violence
SRC			=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ			=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re