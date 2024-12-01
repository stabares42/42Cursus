/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:38:36 by stabares          #+#    #+#             */
/*   Updated: 2024/11/26 19:38:38 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	int	c;

	c = '2';
	printf("%c Es alfanumerico y retorna %d\n", c, ft_isalnum(c));
	c = 'S';
	printf("%c Es alfanumerico y retorna %d\n", c, ft_isalnum(c));
	c = '@';
	printf("%c No es alfanumerico y retorna %d\n", c, ft_isalnum(c));
	return (0);
}
 */