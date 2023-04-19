/*
** EPITECH PROJECT, 2023
** generator_dir
** File description:
** stdout_map
*/
#include "../my.h"

void add_complexity_extend(char *const *buffer, const int_fast32_t width,
                            int_fast32_t i, int_fast32_t e)
{
    if (buffer[i][e] == '1' && buffer[i][e + 1] == '1') {
        int_fast32_t alea = (rand() % ((e + 2) - e + 1) + e);
        buffer[i][alea] = '0';
    }
    if ((i + 2 < width) && (buffer[i][e] == '1') &&
        (buffer[i + 1][e] == '1') && (buffer[i + 2][e] == '1')) {
        int_fast32_t alea = (rand() % ((i + 2) - i + 1) + i);
        buffer[alea][e] = '0';
    }

    return;
}

void add_complexity(char *const *buffer, int_fast32_t width)
{
    for (uint_fast32_t i = 0; buffer[i]; i++) {
        for (uint_fast32_t e = 0; buffer[i][e]; e += 2) {
            add_complexity_extend(buffer, width, i, e);
        }
    }
    return;
}

int_fast32_t stdout_map_extend(char *const *buffer, ...)
{
    va_list args;
    va_start(args, buffer);

    char *fill_buffer = va_arg(args, char*);
    const int_fast32_t height = va_arg(args, int_fast32_t);
    int_fast32_t index = va_arg(args, int_fast32_t);
    int_fast32_t i = va_arg(args, int_fast32_t);

    for (int_fast32_t e = 0; e != height; e++) {
        if (buffer[i][e] == '0')
            fill_buffer[index] = '*';
        if (buffer[i][e] == '1')
            fill_buffer[index] = 'X';
        index++;
    }
    fill_buffer[index] = '\n';
    index++;
    va_end(args);
    return index;
}

void stdout_map(char *const *buffer, int_fast32_t width,
                int_fast32_t height, bool maze_status)
{
    int_fast32_t index = 0;
    const int_fast32_t len_array = len_buffer(buffer, width);
    char *fill_buffer = malloc(sizeof(char) * len_array);

    if (maze_status == false) {
        add_complexity(buffer, width);
    }
    for (int_fast32_t i = 0; i != width; i++) {
        index = stdout_map_extend(buffer, fill_buffer, height, index, i);
    }
    fill_buffer[index - 1] = '\0';
    printf("%s", fill_buffer);
}
