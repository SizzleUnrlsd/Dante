/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier
** File description:
** get_arg
*/
#include "../my.h"

void integration_argument(gen_struct_t *gen, char **av)
{
    gen->get_arg->arg_1 = atoi(av[1]);
    gen->get_arg->agr_2 = atoi(av[2]);
    if (gen->get_arg->arg_1 < 1 || gen->get_arg->agr_2 < 1) {
        exit(84);
    }
    if (av[3] != NULL) {
        gen->get_arg->agr_3 = av[3];
    } else {
        gen->get_arg->agr_3 = NULL;
    }
    if (gen->get_arg->arg_1 == 1 && gen->get_arg->agr_2 == 1) {
        printf("*");
        exit(0);
    }
    return;
}
