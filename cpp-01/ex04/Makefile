CC			=	c++ -std=c++11
CFLAGS		=	-Wall -Werror -Wextra
NAME		=	violence
SRC			=	main.cpp
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
	rm -f output.txt

re: clean all

.PHONY: all clean fclean re