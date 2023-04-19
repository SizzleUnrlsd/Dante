/*
** EPITECH PROJECT, 2023
** generator_dir
** File description:
** change_buffer
*/
#include "../my.h"

void change_buffer(maze_t *maze, char **buffer, bool maze_status)
{
    const int_fast32_t i = maze->width - 1;
    const int_fast32_t j = maze->height - 1;

    if (buffer[i][j - 1] == '1' && buffer[i - 1][j] == '1')
        buffer[i][j - 1] = '0';
    if (buffer[i][j] == '1')
        buffer[i][j] = '0';
    if (buffer[i - 1][j] == '1' && maze_status == false)
        buffer[i - 1][j] = '0';
    return;
}
