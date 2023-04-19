/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-minishell1-clement-antoine.xavier
** File description:
** str_to_word_array.h
*/

#ifndef _STR_TO_WORD_ARRAY_H_
    #define _STR_TO_WORD_ARRAY_H_

    #include <stdlib.h>

typedef struct word_array_s {
    char **words;
    size_t size;
    char *separators;
    char *str;
    size_t index;
} word_array_t;

    #define IN 1
    #define OUT 0

word_array_t *str_to_word_array(const char *str, const char *seperators);
void terminate_word_array(word_array_t *word_array);
int is_separator(char c, const char *seperators);
void print_word_array(word_array_t *word_array);

#endif /* _STR_TO_WORD_ARRAY_H_ */
