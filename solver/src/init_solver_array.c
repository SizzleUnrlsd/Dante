/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier [WSL : Fedora]
** File description:
** init_solver_array.c
*/

#include "solver.h"
#include <stdlib.h>

int init_solver_distances(solver_t *solver)
{
    solver->distances = malloc(sizeof(double *) * solver->height);
    if (solver->distances == NULL)
        return 84;
    for (int i = 0; i < solver->height; i++) {
        solver->distances[i] = malloc(sizeof(double) * solver->width);
        if (solver->distances[i] == NULL)
            return 84;
        for (int j = 0; j < solver->width; j++)
            solver->distances[i][j] = calcul_distance(i, j, solver->height - 1,
                solver->width - 1);
    }
    return 0;
}

int init_solver_visited(solver_t *solver)
{
    solver->visited = malloc(sizeof(int *) * solver->height);
    if (solver->visited == NULL)
        return 84;
    for (int i = 0; i < solver->height; i++) {
        solver->visited[i] = malloc(sizeof(int) * solver->width);
        if (solver->visited[i] == NULL)
            return 84;
        for (int j = 0; j < solver->width; j++)
            solver->visited[i][j] = 0;
    }
    return 0;
}

int init_solver_array(solver_t *solver)
{
    if (init_solver_distances(solver) == 84)
        return 84;
    if (init_solver_visited(solver) == 84)
        return 84;
    return 0;
}
