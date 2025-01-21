/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:14:23 by stabares          #+#    #+#             */
/*   Updated: 2025/01/21 13:43:30 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int			ft_printf(char const *format, ...);
int			ft_printn(unsigned int n);
int			process_conversion(char specifier, va_list args);
char		*ft_itoa_base(unsigned long n, int base);
int			print_integer(int n);
int			print_unsigned(int n);
int			print_hexadecimal(unsigned int n, char specifier);
int			print_pointer(void *ptr);
int			ft_putstr(char *str);
int			ft_putchar(char c);
#endif