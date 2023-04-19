/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier
** File description:
** arg_error_case
*/
#include "../my.h"

static void arg_error_case_extend(char **av, int i, int e)
{
    if (i != 3 && isdigit(av[i][e]) == 0)
        exit(84);
    if (i == 3 && isdigit(av[i][e]) != 0)
        exit(84);
    return;
}

void arg_error_case(char **av)
{
    unsigned int limiter = 3;
    if (av[3] == NULL)
        limiter = 2;

    for (unsigned int i = 1; i <= limiter; i++)
        for (unsigned int e = 0; av[i][e]; e++)
            arg_error_case_extend(av, i, e);

    if (av[3] != NULL && strcmp(av[3], "perfect") != 0)
        exit(84);
    return;
}
