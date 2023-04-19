/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier
** File description:
** init_struct
*/
#include "../my.h"

gen_struct_t *init_struct(void)
{
    gen_struct_t *gen = malloc(sizeof(gen_struct_t));
    gen->garbage = malloc(sizeof(garbage_collector_t *) * LEN_ARRAY_STRUCT);
    gen->get_arg = malloc(sizeof(get_arg_t));
    gen->io = 0;

    return gen;
}
