##
## EPITECH PROJECT, 2023
## B-PSU-100-RUN-1-1-bsnavy-hugo.payet
## File description:
## Makefile
##

SRC	=	lib/*.c

SRC_EXTERN = garbage_collector/*.c

SRC_EXTERN01 = imperfect_maze/*.c

SRC_EXTERN02 = perfect_maze/*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

FLAGS 	=	-W -Wall -Wextra -Werror -O3

TEST_BIN =	unit_tests

TEST_SRC =	tests/*.c

all	:	$(OBJ)
	gcc -o $(NAME) $(FLAGS) $(SRC) $(SRC_EXTERN) $(SRC_EXTERN02)

clean	:
	rm -f $(OBJ)
	rm -f a.out
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.c~

fclean	: clean
	rm -f $(NAME)
	rm -f $(TEST_BIN)

re	: fclean all

$(TEST_BIN): all
	gcc -o $(TEST_BIN) $(FLAGS) $(SRC_00) $(TEST_SRC) --coverage -lcriterion

tests_run:	$(TEST_BIN)
	./$(TEST_BIN)
