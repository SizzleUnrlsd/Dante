/*
** EPITECH PROJECT, 2022
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier [WSL : Fedora]
** File description:
** stack.c
*/

#include "solver.h"
#include <stdlib.h>
#include <stdio.h>

stack_t *init_stack(void)
{
    stack_t *stack = malloc(sizeof(stack_t));
    if (stack == NULL)
        return NULL;
    stack->position = NULL;
    stack->size = 0;
    return stack;
}

int add_to_stack(stack_t *stack, position_t position)
{
    if (stack->position == NULL) {
        stack->position = malloc(sizeof(position_t));
        if (stack->position == NULL)
            return 84;
        stack->position[0] = position;
        stack->size++;
        return 0;
    }
    stack->position = realloc(stack->position, sizeof(position_t) *
        (stack->size + 1));
    if (stack->position == NULL)
        return 84;
    stack->position[stack->size] = position;
    stack->size++;
    return 0;
}

int remove_from_stack(stack_t *stack, position_t *position)
{
    *position = stack->position[stack->size - 1];
    stack->position = realloc(stack->position, sizeof(position_t) *
        (stack->size - 1));
    stack->size--;
    return 0;
}

void terminate_stack(stack_t *stack)
{
    free(stack->position);
    free(stack);
}

void print_stack(stack_t *stack)
{
    for (int i = 0;i < stack->size;i++) {
        printf("x: %u, y: %u\n", stack->position[i].x,
        stack->position[i].y);
    }
}
