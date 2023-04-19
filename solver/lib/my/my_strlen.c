/*
** EPITECH PROJECT, 2022
** B-CPE-100-RUN-1-1-cpoolday04-clement-antoine.xavier
** File description:
** my_strlen.c
*/

int m_strlen(char const *str)
{
    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size;
}
