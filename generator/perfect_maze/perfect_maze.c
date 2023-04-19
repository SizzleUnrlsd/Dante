/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier [WSL : Fedora]
** File description:
** perfect_maze_.c
*/
#include "../my.h"

void perfect_maze(gen_struct_t *gen, bool maze_status)
{
    srand(time(NULL));
    maze_t *maze = malloc(sizeof(maze_t));
    int32_t height = gen->get_arg->arg_1;
    int32_t width = gen->get_arg->agr_2;

    init_maze_struct(maze, width, height);
    char **buffer = init_buffer(maze);
    buffer = init_maze(maze, buffer);
    perfect_algo(maze, buffer);
    change_buffer(maze, buffer, maze_status);
    stdout_map(buffer, maze->width, maze->height, maze_status);
    return;
}
