#include "ft_printf.h"
#include <stdio.h>

int ft_choix(va_list list, char c)
{
    if (c == 's')
        return(ft_putstr((char*)va_arg(list, char*)));
    else if (c == 'd')
        return(ft_putnbr((int)va_arg(list, int)));
    // if (c == 'c')
    //     return(ft_putchar((char)va_arg(list, char)));
    return (1);
}

int ft_printf(const char *format, ...)
{
    va_list list;
    va_start (list, format);

    int i;
    int count;

    i = 0;
    count = 0;
    while (format[i])
    {
        if (format[i] != '%')
        {
            ft_putchar(format[i]);
            count += 1;
        }
        else if(format[i] == '%')
        {
            count += ft_choix(list, format[++i]);
        }
        i++;
    }
    va_end(list);
    return(count);
}

int main()
{
    printf("Le nombre est :%d ", ft_printf("B%d%d%d\n", 42, 87, 43));
}