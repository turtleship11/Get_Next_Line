CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line

SRC = get_next_line.c get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)

INCLUDE = -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
