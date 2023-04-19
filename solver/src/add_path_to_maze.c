/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier [WSL : Fedora]
** File description:
** add_path_to_maze.c
*/

#include "solver.h"
#include "my.h"
#include "str_to_word_array.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void add_path_to_maze(solver_t *solver)
{
    int x = 0, y = 0;
    for (int i = 0;i < solver->path->size;i++) {
        y = solver->path->position[i].y;
        x = solver->path->position[i].x;
        solver->maze[x][y] = 'o';
    }
}
