#include "ft_printf.h"

int     nbr_len(int nb)
{
    int i;

    i = 1;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while(nb > 9)
	{
		nb /= 10;
		i++;
	}
	return(i);
}

int	ft_putnbr(int nbr)
{
	long	nb;
	int		i;
	char	c[10];

	nb = nbr;
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	i = 0;
	while (nb > 0)
	{
		c[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_put(c[i]);
		i--;
	}
	return (nbr_len(nbr));
}