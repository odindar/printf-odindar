/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odindar <odindar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 03:30:29 by odindar           #+#    #+#             */
/*   Updated: 2026/05/13 03:30:29 by odindar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int num, const char format)
{
	int		len;
	char	*base;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num >= 16)
		len += ft_print_hex(num / 16, format);
	len += ft_print_char(base[num % 16]);
	return (len);
}

static int	ft_put_ptr(unsigned long long num)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (num >= 16)
		len += ft_put_ptr(num / 16);
	len += ft_print_char(base[num % 16]);
	return (len);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_print_str("(nil)"));
	len += ft_print_str("0x");
	len += ft_put_ptr(ptr);
	return (len);
}
