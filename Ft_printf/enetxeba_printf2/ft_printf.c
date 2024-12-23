/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enetxeba <enetxeba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:57:36 by endika            #+#    #+#             */
/*   Updated: 2024/12/23 11:05:03 by enetxeba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *src, ...)
{
	va_list	args;
	int		index;
	int		w_count;

	w_count = 0;
	index = -1;
	va_start(args, src);
	while (src[++index])
	{
		w_count += parse(src, args, &index);
	}
	va_end(args);
	return (w_count);
}

int	parse(char const *src, va_list args, int *index)
{
	int	w_count;

	w_count = 0;
	if (src[*index] == '%')
	{
		if (src[*index + 1] == '%')
		{
			ft_putchar_fd ('%', 1);
			*index += 1;
			w_count++;
		}
		else if (isformat(src[*index + 1]))
		{
			w_count += print_format(args, src[++(*index)]);
		}
		else
			ft_putchar_fd(src[*index++], 1);
	}
	else
	{
		ft_putchar_fd(src[*index], 1);
		w_count++;
	}
	return (w_count);
}

int	print_format(va_list args, char c)
{
	int	w_count;

	w_count = 0;
	if (c == 'd' || c == 'i')
		w_count += ft_putnbr_int(va_arg(args, int), base(c));
	else if (c == 'x' || c == 'X' || c == 'u')
		w_count += ft_putnbr_un(va_arg(args, unsigned int), base(c));
	else if (c == 'p')
		w_count += ft_putnbr_lon(va_arg(args, unsigned long), base(c));
	else if (c == 'c' )
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		w_count ++;
	}
	else
		w_count += ft_putstring(va_arg(args, char *));
	return (w_count);
}

int	isformat(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
			c == 'u' || c == 'x' || c == 'X');
}

int	ft_putstring(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
}
