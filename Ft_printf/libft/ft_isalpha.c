/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:55:12 by stabares          #+#    #+#             */
/*   Updated: 2024/12/19 14:44:28 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/* int	main(void)
{
	int	c;

	c = 'A';
	printf("%c Es alfabetico y retorna %d\n", c, ft_isalpha(c));

	c = '1';
	printf("%c No es alfabetico y retorna %d\n", c, ft_isalpha(c));
	return (0);
}*/