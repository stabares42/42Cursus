/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:09:35 by stabares          #+#    #+#             */
/*   Updated: 2024/11/26 20:09:39 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 127)
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	c;

	c = '$';
	printf("%c Es imprimible y retorna %d\n", c, ft_isprint(c));
	c = 190;
	printf("%c No es imprimible y retorna %d\n", c, ft_isprint(c));
	return (0);
} */
