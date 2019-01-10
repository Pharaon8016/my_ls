 
##
## EPITECH PROJECT, 2018
## CPE_solostumper_2_2018
## File description:
## Makefile
##

SRC	=	main.c\
		my_strlen.c\
		my_putstr.c\
		my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls


all : $(NAMELIB) $(NAME)

$(NAME):
	gcc -g $(SRC) -Wall -Wextra -o $(NAME)

$(NAMELIB):
	gcc -c -g $(LIB) -Wall
	ar rc $(NAMELIB) $(OBJLIB)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all