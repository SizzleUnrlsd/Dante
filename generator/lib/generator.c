/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier
** File description:
** generator
*/
#include "../my.h"

int main(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        exit(84);
    (void) av;
    gen_struct_t *gen = init_struct();
    arg_error_case(av);
    integration_argument(gen, av);
    set_maze(gen);
    exit_function(gen);
    return 0;
}
