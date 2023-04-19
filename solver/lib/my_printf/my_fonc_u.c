/*
** EPITECH PROJECT, 2022
** B-CPE-101-RUN-1-1-myprintf-kovalen-dimitri.ramaretty
** File description:
** my_fonc_u
*/

#include <stdarg.h>
#include "my_printf.h"

int my_fonc_u(va_list *param_list, format_flag_t *format_flag)
{
    int count_char = 0;
    int num = va_arg(*param_list, int);
    count_char += print_width_space(format_flag->width);
    count_char += my_put_nbr_base(num, "0123456789",
        format_flag->length_modifier);
    return count_char;
}
