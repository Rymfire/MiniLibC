##
## EPITECH PROJECT, 2018
## Makefile
## File description
## Makefile
##

NAME	=	libasm.so

SDIR	=	src

SRC		=	$(SDIR)/strlen.asm	\
			$(SDIR)/strchr.asm	\
			$(SDIR)/memset.asm	\
			$(SDIR)/memcpy.asm	\
			$(SDIR)/strcmp.asm	\
			$(SDIR)/memmove.asm	\
			$(SDIR)/strncmp.asm	\
			$(SDIR)/rindex.asm	\
			$(SDIR)/strpbrk.asm	\
			$(SDIR)/strcspn.asm	\
#			$(SDIR)/strlwr.asm	\

OBJ		=	$(SRC:.asm=.o)

CC		=	ld

ASM		=	nasm

RM		=	rm -f

ASFLAGS	=	-felf64

LDFLAGS	=	-fPIC -shared

all:    $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@
	make -C tests/

%.o: %.asm
	$(ASM) $(ASFLAGS) $< -o $@

tests_run: all
	make tests_run -C tests/

clean:
	$(RM) $(OBJ)
	make clean -C tests/

fclean: clean
	$(RM) $(NAME)
	make fclean -C tests/

rclean:
	$(RM) vgcore.*
	make rclean -C tests/

re: fclean all
	make re -C tests/

.PHONY: all clean fclean rclean re
