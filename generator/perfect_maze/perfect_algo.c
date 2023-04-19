/*
** EPITECH PROJECT, 2023
** generator_dir
** File description:
** perfect_algo
*/
#include "../my.h"

void north_cell(maze_t *maze, char *const *buffer,
                int_fast32_t i, int_fast32_t j)
{
    if (i - 1 >= 0 && buffer[i - 1][j] == '1') {
        maze->north = 1;
    }
    if (j - 1 >= 0 && buffer[i][j - 1] == '1') {
        maze->west = 1;
    }
    return;
}

void one_wall(maze_t *maze, char **buffer, int_fast32_t i, int_fast32_t j)
{
    if (i - 1 >= 0 && maze->north == 1 && maze->west == 0) {
        buffer[i - 1][j] = '0';
    }
    if (j - 1 >= 0 && maze->north == 0 && maze->west == 1) {
        buffer[i][j - 1] = '0';
    }
    return;
}

void square_wall(char **buffer, int_fast32_t i, int_fast32_t j)
{
    int_fast32_t random = rand() % 2;
    if (j - 1 >= 0 && random == 0) {
        buffer[i][j - 1] = '0';
    }
    if (i - 1 >= 0 && random == 1) {
        buffer[i - 1][j] = '0';
    }
    return;
}

void perfect_algo_extend(maze_t *maze, char **buffer,
                        int_fast32_t i, int_fast32_t e)
{
    if (i == 0) {
        buffer[i][e] = '0';
    }
    north_cell(maze, buffer, i, e);
    one_wall(maze, buffer, i, e);
    if (maze->north == 1 && maze->west == 1) {
        square_wall(buffer, i, e);
    }
    return;
}

void perfect_algo(maze_t *maze, char **buffer)
{
    for (int_fast32_t i = 0; i < maze->width; i += 2) {
        maze->north = 0;
        maze->west = 0;
        for (int_fast32_t e = 0; e < maze->height; e += 2) {
            perfect_algo_extend(maze, buffer, i, e);
        }
    }
    return;
}
