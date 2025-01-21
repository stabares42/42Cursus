/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:23:58 by stabares          #+#    #+#             */
/*   Updated: 2025/01/16 17:26:02 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printn(unsigned int n)
{
	int	result;

	result = 0;
	if (n < 10)
	{
		result += ft_putchar(n + '0');
	}
	else
	{
		result += ft_printn(n / 10);
		result += ft_putchar((n % 10) + '0');
	}
	return (result);
}

int	print_integer(int n)
{
	int		result;

	result = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		result += 1;
		result += ft_printn(n * -1);
	}
	else
	{
		result += ft_printn(n);
	}
	return (result);
}

int	print_unsigned(int n)
{
	return (ft_printn((unsigned int)n));
}

int	print_hexadecimal(unsigned int n, char specifier)
{
	char	*str;
	int		len;
	int		i;

	str = ft_itoa_base(n, 16);
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (specifier == 'x' && str[i] >= 'A' && str[i] <= 'F')
			str[i] = str[i] + 'a' - 'A';
		else if (specifier == 'X' && str[i] >= 'a' && str[i] <= 'f')
			str[i] = str[i] - 'a' + 'A';
		i++;
	}
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	print_pointer(void *ptr)
{
	unsigned long	address;
	char			*str;
	int				len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (unsigned long)ptr;
	str = ft_itoa_base(address, 16);
	if (!str)
		return (0);
	ft_putstr("0x");
	len = ft_putstr(str);
	free(str);
	return (len + 2);
}
