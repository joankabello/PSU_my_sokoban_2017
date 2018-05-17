##
## EPITECH PROJECT, 2017
## projekt
## File description:
## projekt
##

SRC	=	my_popup.c			\
		./include/window.c		\
		./include/my_strlen.c		\
		./include/my_putstr.c		\
		./include/my_put_nbr.c		\
		./include/my_putchar.c		\
		./include/move.c		\
		./include/my_strdup.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I./include

LDFLAGS	=	-lncurses

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm *.gcda -f $(NAME)
	rm *.gcno -f $(NAME)
	rm *~ -f $(NAME)
	rm *# -f $(NAME)

re:	fclean all
