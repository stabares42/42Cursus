/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:43:32 by stabares          #+#    #+#             */
/*   Updated: 2024/12/05 16:52:39 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

/* int	main(void)
{
	char	str1[50];
	char	str2[50];
	char	str3[50];

	strcpy(str1, "	 -271202");
	strcpy(str2, "42");
	strcpy(str3, "+247act");
	printf("Resultado 1: %d\n", ft_atoi(str1));
	printf("Resultado 2: %d\n", ft_atoi(str2));
	printf("Resultado 3: %d\n", ft_atoi(str3));
	return (0);
} */
