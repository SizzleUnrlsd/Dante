/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-dante-clement-antoine.xavier
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct get_arg_s {
        int_fast32_t arg_1;
        int_fast32_t agr_2;
        char *agr_3;
    }get_arg_t;

    typedef struct garbage_collector_s {
        unsigned int index;
        void *pointer;
    }garbage_collector_t;

    typedef struct maze_s {
        int_fast32_t north;
        int_fast32_t west;
        int_fast32_t width;
        int_fast32_t height;
        int_fast32_t colonne;
    }maze_t;

    typedef struct gen_struct_s {
        get_arg_t *get_arg;
        garbage_collector_t **garbage;
        unsigned int io;
    }gen_struct_t;

#endif /* !STRUCT_H_ */
