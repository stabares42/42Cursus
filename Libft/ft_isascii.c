/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:47:11 by stabares          #+#    #+#             */
/*   Updated: 2024/11/26 19:47:13 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	c;

	c = 's';
	printf("%c Es ASCII estardar y retorna %d\n", c, ft_isascii(c));
	c = 169;
	printf("%c No es un ASCII estandar y retorna %d\n", c, ft_isascii(c));
	return (0);
}
 */