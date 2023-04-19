/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** library with prototypes
*/

#ifndef MY_H_
    #define MY_H_
    #define LIMITER 2.9

    #include <time.h>
    #include <stdint.h>
    #include <ctype.h>
    #include <errno.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <string.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <sys/types.h>

    #define LEN_ARRAY_STRUCT 100000

    #include "struct.h"

#endif /* MY_H_ */

void square_wall(char **buffer, int_fast32_t i, int_fast32_t j);
void perfect_maze(gen_struct_t *gen, bool maze_status);
void one_wall(maze_t *maze, char **buffer, int_fast32_t i, int_fast32_t j);
void arg_error_case(char **av);
gen_struct_t *init_struct(void);
char **init_buffer(maze_t *maze);
void set_maze(gen_struct_t *gen);
void exit_function(gen_struct_t *gen);
void *malloc_attribut(size_t size, ...);
char **init_maze(maze_t *maze, char **buffer);
void perfect_algo(maze_t *maze, char **buffer);
int_fast32_t len_buffer(char *const *buffer, const int_fast32_t width);
void garbage_collector(void *p, gen_struct_t *gen);
void garbage_uncollector(garbage_collector_t *garbage);
void integration_argument(gen_struct_t *gen, char **av);
void change_buffer(maze_t *maze, char **buffer, bool maze_status);
void init_maze_struct(maze_t *maze, int_fast32_t width, int_fast32_t height);
void north_cell(maze_t *maze, char *const *buffer,
                int_fast32_t i, int_fast32_t j);
void stdout_map(char *const *buffer, int_fast32_t width,
                int_fast32_t height, bool maze_status);
garbage_collector_t **realloc_struct(garbage_collector_t **p,
                                size_t size, unsigned int len);
