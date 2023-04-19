/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier
** File description:
** malloc_attribut
*/
#include "../my.h"

void *malloc_attribut(size_t size, ...)
{
    va_list ap;
    va_start(ap, size);
    size_t size_off = va_arg(ap, size_t);
    gen_struct_t *gen = va_arg(ap, gen_struct_t *);

    void *p = malloc(size_off);
    if (p == NULL)
        exit(84);
    garbage_collector(p, gen);

    va_end(ap);
    return p;
}
