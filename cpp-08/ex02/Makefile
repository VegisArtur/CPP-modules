CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++17
NAME		=	container
SRC			=	main.cpp
OBJ			=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)
	touch numbers.txt

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf numbers.txt

re: clean all

.PHONY: all clean fclean re