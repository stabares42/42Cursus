/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:54:27 by stabares          #+#    #+#             */
/*   Updated: 2025/01/21 14:58:52 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		printed_chars;
	int		i;

	printed_chars = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed_chars += process_conversion(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}

int	process_conversion(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_integer(va_arg(args, int)));
	else if (specifier == 'u')
		return (print_unsigned(va_arg(args, int)));
	else if (specifier == 'x' || specifier == 'X')
		return (print_hexadecimal(va_arg(args, unsigned int), specifier));
	else if (specifier == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}
