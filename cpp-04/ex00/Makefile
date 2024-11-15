CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++11
NAME		=	zoo
SRC			=	main.cpp animal.cpp dog.cpp cat.cpp
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