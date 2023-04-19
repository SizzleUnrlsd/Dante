/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier
** File description:
** exit_function
*/
#include "../my.h"

void exit_function(gen_struct_t *gen)
{
    for (unsigned int i = 0; i != gen->io; i++) {
        garbage_uncollector(gen->garbage[i]);
    }
    free(gen->garbage);
    free(gen->get_arg);
    free(gen);

    return;
}
