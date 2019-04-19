##
## EPITECH PROJECT, 2018
## Makefile
## File description
## Makefile
##

NAME	=	unit_tests

SRC		=	asm_tests.c	\

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror --coverage

LDFLAGS	=	-lcriterion -lgcov -ldl

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@

tests_run: $(NAME)
	./$<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

rclean:
	$(RM) vgcore.*
	$(RM) *.gcda
	$(RM) *.gcno

re: fclean all

.PHONY: all clean fclean rclean re
