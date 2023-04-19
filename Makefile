##
## EPITECH PROJECT, 2022
## B-CPE-110-RUN-1-1-bsantman-clement-antoine.xavier
## File description:
## Makefile
##

all:
	make all -C ./generator
	make all -C ./solver

clean:
	make clean -C ./generator
	make clean -C ./solver

fclean:
	make fclean -C ./generator
	make fclean -C ./solver

re: fclean all
