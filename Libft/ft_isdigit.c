/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:40:32 by stabares          #+#    #+#             */
/*   Updated: 2024/11/26 18:40:38 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	c;

	c = '2';
	printf("%c Es un digito y retorna %d\n", c, ft_isdigit(c));
	c = 'A';
	printf("%c No es un digito y retorna %d\n", c, ft_isdigit(c));
	return (0);
} */
