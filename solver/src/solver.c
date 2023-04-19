/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier
** File description:
** solver.c
*/

#include "solver.h"
#include "my.h"
#include "str_to_word_array.h"

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

int read_file(solver_t *solver)
{
    if (stat(solver->file_path, &solver->metadata) == -1)
        return 84;
    solver->buffer_size = solver->metadata.st_size;
    if (solver->buffer_size == 0 || !S_ISREG(solver->metadata.st_mode))
        return 84;
    solver->buffer = malloc(sizeof(char) * (solver->buffer_size + 1));
    if (solver->buffer == NULL)
        return 84;
    solver->buffer[solver->buffer_size] = '\0';
    int file_fd = open(solver->file_path, O_RDONLY);
    if (file_fd == -1)
        return 84;
    if (read(file_fd, solver->buffer, solver->buffer_size) == -1)
        return 84;
    close(file_fd);
    return 0;
}

int init_solver_objects(solver_t *solver)
{
    if (read_file(solver) == 84)
        return 84;
    solver->maze = my_str_to_word_array(solver->buffer);
    if (solver->maze == NULL)
        return 84;
    for (solver->height = 0;solver->maze[solver->height] != NULL;
        solver->height++);
    for (solver->width = 0;solver->maze[0][solver->width] != '\0';
        solver->width++);
    if (init_solver_array(solver) == 84)
        return 84;
    return 0;
}

solver_t *init_solver(int argc, char **argv)
{
    solver_t *solver = malloc(sizeof(solver_t));
    if (solver == NULL)
        return NULL;
    if (argc != 2)
        return NULL;
    solver->file_path = argv[1];
    if (init_solver_objects(solver) == 84)
        return NULL;
    if (check_maze(solver) == 84)
        return NULL;
    solver->path = init_stack();
    if (solver->path == NULL)
        return NULL;
    return solver;
}

void terminate_solver(solver_t *solver)
{
    for (int i = 0; i < solver->height; i++)
        free(solver->visited[i]);
    free(solver->visited);
    for (int i = 0; i < solver->height; i++)
        free(solver->maze[i]);
    free(solver->maze);
    for (int i = 0; i < solver->height; i++)
        free(solver->distances[i]);
    free(solver->distances);
    terminate_stack(solver->path);
    free(solver->buffer);
    free(solver);
}
