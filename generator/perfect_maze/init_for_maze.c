/*
** EPITECH PROJECT, 2023
** generator_dir
** File description:
** init_for_maze
*/
#include "../my.h"

void init_maze_struct(maze_t *maze, int_fast32_t width, int_fast32_t height)
{
    maze->north = 0;
    maze->west = 0;
    maze->height = height;
    maze->width = width;
    return;
}

char **init_buffer(maze_t *maze)
{
    const int_fast32_t hauteur = maze->width;
    const int_fast32_t largeur = maze->height;
    char **buffer = malloc(sizeof(char *) * (hauteur + 1));

    for (int_fast32_t i = 0; i != hauteur; i++) {
        buffer[i] = malloc(sizeof(char) * largeur + 1);
    }
    buffer[hauteur] = NULL;
    return buffer;
}

int_fast32_t init_maze_extend(char **buffer, int_fast32_t i, int_fast32_t j)
{
    if (j % 2 == 0 && i % 2 == 0) {
        buffer[i][j] = '0';
    }
    if (j % 2 != 0 && i % 2 == 0) {
        buffer[i][j] = '1';
    }
    if (i % 2 != 0) {
        buffer[i][j] = '1';
    }
    j++;
    return j;
}

char **init_maze(maze_t *maze, char **buffer)
{
    int_fast32_t j = 0;
    for (int_fast32_t i = 0; i < maze->width; i++) {
        j = 0;
        for (;j < maze->height;) {
            j = init_maze_extend(buffer, i, j);
        }
        buffer[i][j] = '\0';
    }
    return buffer;
}
