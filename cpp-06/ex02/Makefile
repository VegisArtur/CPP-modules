CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++17
NAME		=	types
SRC			=	main.cpp A.cpp B.cpp C.cpp Base.cpp
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