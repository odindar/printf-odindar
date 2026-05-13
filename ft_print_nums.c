/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odindar <odindar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 03:30:32 by odindar           #+#    #+#             */
/*   Updated: 2026/05/13 03:30:32 by odindar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
