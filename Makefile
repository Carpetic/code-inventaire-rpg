##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile to compile the project
##

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	inventory

CFLAGS	=	-W -Wall -Wextra

LDFLAGS	=	-lcsfml-window -lcsfml-graphics -lcsfml-system

LINKFLAGS	=	-I./includes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LINKFLAGS) $(LDFLAGS) -o $(NAME)
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> compile -> OK\033[0m"

clean:
	$(RM) *~
	$(RM) \#*#
	$(RM) $(OBJ)
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> clean -> OK\033[0m"

fclean: clean
	$(RM) $(NAME)
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> fclean -> OK\033[0m"

re:	fclean all
