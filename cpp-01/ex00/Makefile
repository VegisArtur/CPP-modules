CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra
NAME		=	BraiiiiiiinnnzzzZ
SRC			=	main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
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