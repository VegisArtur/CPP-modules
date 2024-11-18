CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++11
NAME		=	zoo
SRC			=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
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