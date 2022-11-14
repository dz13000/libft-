#include "ft_printf.h"

void    ft_put(char c)
{
    write(1, &c, 1);
}