/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:54:27 by stabares          #+#    #+#             */
/*   Updated: 2025/01/10 21:36:02 by stabares         ###   ########.fr       */
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
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (print_hexadecimal(va_arg(args, unsigned int), specifier));
	else if (specifier == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (specifier == '%')
		return (write(1, "%", 1));
	return (0);
}

char	*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned int	len;
	unsigned int	temp;

	len = 1;
	temp = n;
	while (temp >= 10)
	{
		temp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static int	ft_num_len(unsigned long n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)base)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long n, int base)
{
	char	*str;
	int		len;
	char	*digits;

	digits = "0123456789abcdef";
	len = ft_num_len(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = digits[n % base];
		n /= base;
	}
	return (str);
}

/* int main(void)
{
	char *str = "HOLA";
	
    printf("Character test original: %c\n", 'S');
    ft_printf("Character test: %c\n", 'S');
    printf("String test original: %s\n", "42 is amazing!");
    ft_printf("String test: %s\n", "42 is amazing!");
	printf("Null string test original: %p\n", NULL);
    ft_printf("Null string test: %p\n", NULL);
    printf("Digit test original: %d\n", 42);
    ft_printf("Digit test: %d\n", 42);
    printf("Integer test orginal: %i\n", -42);
    ft_printf("Integer test: %i\n", -42);
    printf("Unsigned test original: %u\n", 42);
    ft_printf("Unsigned test: %u\n", 42);
    printf("Hexadecimal test original: (uppercase): %X\n", 222);
    ft_printf("Hexadecimal test (uppercase): %X\n", 222);
    printf("Hexadecimal test original: (lowercase): %x\n", 222);
    ft_printf("Hexadecimal test (lowercase): %x\n", 222);
    printf("Pointer test original: %p\n", &str);
    ft_printf("Pointer test: %p\n", &str);
	printf("Percent test original: %%\n");
	ft_printf("Percent test: %%\n");
	return (0);
} */