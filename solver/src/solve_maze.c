/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier [WSL : Fedora]
** File description:
** solve_maze.c
*/

#include "solver.h"
#include <stdlib.h>
#include <stdio.h>

int move_is_possible(solver_t *solver, position_t current, position_t move)
{
    if (current.x + move.x >= 0 && current.x + move.x < solver->height &&
        current.y + move.y >= 0 && current.y + move.y < solver->width &&
        solver->visited[current.x + move.x][current.y + move.y] == 0 &&
        solver->maze[current.x + move.x][current.y + move.y] == '*')
        return 1;
    return 0;
}

void sort_possible_move_loop(solver_t *solver, position_t current,
    position_t *possible_move, position_t pos)
{
    position_t tmp = {0, 0};
    if (move_is_possible(solver, current, possible_move[pos.y]) == 0)
        return;
    if (move_is_possible(solver, current, possible_move[pos.x]) == 0)
        return;
    if (solver->distances[current.x + possible_move[pos.y].x]
        [current.y + possible_move[pos.y].y] >
        solver->distances[current.x + possible_move[pos.x].x]
        [current.y + possible_move[pos.x].y]) {
        tmp = possible_move[pos.y];
        possible_move[pos.y] = possible_move[pos.x];
        possible_move[pos.x] = tmp;
    }
}

void sort_possible_move(solver_t *solver, position_t current,
    position_t *possible_move)
{
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            sort_possible_move_loop(solver, current, possible_move,
                (position_t){i, j});
        }
    }
}

int test_move(solver_t *solver, position_t *current,
    position_t *possible_move, int *move)
{
    position_t tmp = {0, 0};
    sort_possible_move(solver, *current, possible_move);
    for (int i = 0;i < 4;i++) {
        if (move_is_possible(solver, *current, possible_move[i])) {
            current->x += possible_move[i].x;
            current->y += possible_move[i].y;
            add_to_stack(solver->path, *current);
            solver->visited[current->x][current->y] = 1;
            *move = 1;
            break;
        }
    }
    if (*move == 0) {
        if (remove_from_stack(solver->path, &tmp) == 84)
            return 84;
        *current = get_stack_head(solver->path);
    }
    return 0;
}

int solve_maze(solver_t *solver)
{
    position_t start = {0, 0};
    position_t end = {solver->height - 1, solver->width - 1};
    position_t current = {0, 0};
    position_t possible_move[4] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
    int move = 0;
    add_to_stack(solver->path, start);
    solver->visited[start.x][start.y] = 1;
    while (!equal_position(current, end)) {
        move = 0;
        if (test_move(solver, &current, possible_move, &move) == 84)
            return 84;
    }
    return 0;
}
