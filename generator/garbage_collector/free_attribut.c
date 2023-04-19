/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** free_attribut
*/
#include "../my.h"

void free_attribut(void *p, ...)
{
    va_list ap;
    va_start(ap, p);

    p = va_arg(ap, void*);
    gen_struct_t *gen = va_arg(ap, gen_struct_t *);

    unsigned int i = 0;
    for (; gen->garbage[i]; i++)
        if (i > 0 && gen->garbage[i - 1]->index < gen->garbage[i]->index)
            continue;
        else
            break;
    for (unsigned int index = 0; index != i; index++)
        if (gen->garbage[index]->pointer == p)
                garbage_uncollector(gen->garbage[index]);
    return;
}
