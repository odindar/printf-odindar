/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odindar <odindar@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 03:30:36 by odindar           #+#    #+#             */
/*   Updated: 2026/05/13 03:30:36 by odindar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_eval(va_list args, const char format)
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_print_char('%'));
	return (0);
}

static int	ft_process(const char *format, int *i, va_list args)
{
	if (format[*i] == '%')
	{
		if (format[*i + 1] == '\0')
			return (-1);
		(*i)++;
		return (ft_format_eval(args, format[*i]));
	}
	return (ft_print_char(format[*i]));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		print_length;
	int		temp;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	print_length = 0;
	while (format[i])
	{
		temp = ft_process(format, &i, args);
		if (temp == -1)
		{
			va_end(args);
			return (-1);
		}
		print_length += temp;
		i++;
	}
	va_end(args);
	return (print_length);
}
