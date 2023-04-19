/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier [WSL : Fedora]
** File description:
** position.c
*/

#include "solver.h"
#include <stdlib.h>

int equal_position(position_t pos1, position_t pos2)
{
    if (pos1.x == pos2.x && pos1.y == pos2.y)
        return 1;
    return 0;
}
