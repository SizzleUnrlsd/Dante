/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier [WSL : Fedora]
** File description:
** check_maze.c
*/

#include "solver.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int check_maze(solver_t *solver)
{
    for (int i = 0; solver->buffer[i] != '\0'; i++) {
        if (solver->buffer[i] != '*' && solver->buffer[i] != '\n'
            && solver->buffer[i] != '\0' && solver->buffer[i] != 'X')
            return 84;
    }
    if (solver->maze[0][0] != '*' || solver->maze[solver->height - 1]
        [solver->width - 1] != '*')
        return 84;
    for (int i = 0; solver->maze[i] != NULL; i++) {
        if ((int)strlen(solver->maze[i]) != solver->width)
            return 84;
    }
    return 0;
}
