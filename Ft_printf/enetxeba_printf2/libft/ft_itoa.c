/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endika <endika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:19:15 by enetxeba          #+#    #+#             */
/*   Updated: 2024/11/29 18:46:13 by endika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	num_len(int n, int *dig_num)
{
	*dig_num = 0;
	if (n == 0)
	{
		(*dig_num)++;
		return ;
	}
	while (n != 0)
	{
		n /= 10;
		(*dig_num)++;
	}
}

static void	isneg(int *n, int *is_neg, int *dig_num)
{
	if (*n < 0)
	{
		*n = -(*n);
		*is_neg = 1;
		(*dig_num)++;
	}
}

char	*ft_itoa(int n)
{
	int		dig_num;
	int		x;
	char	*ret;
	int		is_neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	is_neg = 0;
	num_len(n, &dig_num);
	isneg(&n, &is_neg, &dig_num);
	ret = malloc(sizeof(char) * (dig_num + 1));
	if (!ret)
		return (NULL);
	x = dig_num -1;
	if (is_neg)
		ret[0] = '-';
	while (n != 0)
	{
		ret[x--] = (n % 10) + '0';
		n /= 10;
	}
	ret[dig_num] = '\0';
	return (ret);
}
