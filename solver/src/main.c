/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier [WSL : Fedora]
** File description:
** main.c
*/

#include "solver.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    solver_t *solver = init_solver(argc, argv);
    if (solver == NULL)
        return 84;
    if (solve_maze(solver) == 84)
        return 84;
    add_path_to_maze(solver);
    if (print_maze(solver) == 84)
        return 84;
    terminate_solver(solver);
    return 0;
}
