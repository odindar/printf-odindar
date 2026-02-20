#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int		len;
	long	num;

	len = 0;
	num = n;
	if (num < 0)
	{
		len += ft_print_char('-');
		num = -num;
	}
	if (num > 9)
		len += ft_print_nbr(num / 10);
	len += ft_print_char((num % 10) + '0');
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_print_unsigned(n / 10);
	len += ft_print_char((n % 10) + '0');
	return (len);
}