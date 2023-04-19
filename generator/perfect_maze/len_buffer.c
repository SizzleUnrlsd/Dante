/*
** EPITECH PROJECT, 2023
** generator_dir
** File description:
** len_buffer
*/
#include "../my.h"

int_fast32_t len_buffer(char *const *buffer, const int_fast32_t width)
{
    uint_fast32_t count = width;

    for (uint_fast32_t i = 0; buffer[i]; i++) {
        for (uint_fast32_t e = 0; buffer[i][e]; e++) {
            count++;
        }
    }
    return count;
}
