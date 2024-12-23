/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enetxeba <enetxeba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:36:25 by endika            #+#    #+#             */
/*   Updated: 2024/12/23 11:14:47 by enetxeba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

char	*base(char c)
{
	char	*ret;

	ret = NULL;
	if (c == 'd' || c == 'i' || c == 'u')
		ret = ft_strdup("0123456789");
	else if (c == 'p' || c == 'x')
		ret = ft_strdup("0123456789abcdef");
	else if (c == 'X')
		ret = ft_strdup("0123456789ABCDEF");
	return (ret);
}

int	ft_putnbr_int(int nbr, char *base)
{
	int		w_count;
	long	trs_nbr;

	trs_nbr = nbr;
	w_count = 0;
	if (nbr < 0)
	{
		trs_nbr = -trs_nbr ;
		ft_putchar_fd('-', 1);
		(w_count)++;
	}
	else
		trs_nbr = nbr;
	ft_put(trs_nbr, base, &w_count);
	free (base);
	return (w_count);
}

int	ft_putnbr_un(unsigned int nbr, char *base)
{
	int	w_count;

	w_count = 0;
	ft_put((long)nbr, base, &w_count);
	free (base);
	return (w_count);
}

int	ft_putnbr_lon( unsigned long nbr, char *base)
{
	int	w_count;

	if (!nbr)
	{
		ft_putstr_fd("(nil)", 1);
		free (base);
		return (5);
	}
	w_count = 2;
	ft_putstr_fd("0x", 1);
	ft_put((long) nbr, base, &w_count);
	free (base);
	return (w_count);
}

void	ft_put( unsigned long nbr, char *base, int *w_count)
{
	unsigned long	baselen;
	char			dig;

	baselen = (long)ft_strlen(base);
	if (nbr > baselen -1)
	{
		ft_put(nbr / baselen, base, w_count);
	}
	dig = base[nbr % baselen];
	ft_putchar_fd(dig, 1);
	(*w_count)++;
	return ;
}
