/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier [WSL : Fedora]
** File description:
** stack_util.c
*/

#include "solver.h"

position_t get_stack_head(stack_t *stack)
{
    return stack->position[stack->size - 1];
}
