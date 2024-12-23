/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enetxeba <enetxeba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:39:27 by endika            #+#    #+#             */
/*   Updated: 2024/12/23 11:08:30 by enetxeba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(char const *src, ...);
int		print_format(va_list args, char c);
int		isformat(char c);
char	*base(char c);
int		ft_putnbr_int(int nbr, char *base);
int		ft_putnbr_un(unsigned int nbr, char *base);
int		ft_putnbr_lon(unsigned long nbr, char *base);
void	ft_put(unsigned long nbr, char *base, int *w_count);
int		parse(char const *src, va_list args, int *index);
int		ft_putstring(char *str);

#endif
