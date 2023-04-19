/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier
** File description:
** switch_mode_maze
*/
#include "../my.h"

void set_maze(gen_struct_t *gen)
{
    bool maze_status = true;

    if (gen->get_arg->agr_3 == NULL) {
        maze_status = false;
    }
    perfect_maze(gen, maze_status);
    return;
}
