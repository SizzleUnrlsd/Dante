/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier [WSL : Fedora]
** File description:
** print_maze.c
*/

#include "solver.h"
#include <stdlib.h>
#include <unistd.h>

int print_maze(solver_t *solver)
{
    for (int i = 0; i < solver->height; i++) {
        write(1, solver->maze[i], (size_t)solver->width);
        if (i != solver->height - 1)
            write(1, "\n", 1);
    }
    return 0;
}
