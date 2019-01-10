/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** my_putstr
*/

#include <unistd.h>

extern int my_strlen(char const *str);

void my_putchar(char c)
{
    write (1, &c, 1);
}

void my_putchar_error(char c)
{
    write (2, &c, 1);
}

int my_putstr_error(char const *str)
{
    int index;
    index = 0;
    while (index < my_strlen(str)){
        my_putchar_error(str[index]);
        ++index;
    }
    return (0);
}

int my_putstr(char const *str)
{
    int index;
    index = 0;
    while (index < my_strlen(str)){
        my_putchar(str[index]);
        ++index;
    }
    return (0);
}
