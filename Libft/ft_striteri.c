/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:10:12 by stabares          #+#    #+#             */
/*   Updated: 2024/12/19 14:35:40 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* void	ft_example(unsigned int i, char *c)
{
	*c = *c + i;
}

int	main(void)
{
	char	str[] = "abcd";

	printf("Antes de ft_striteri: %s\n", str);
	ft_striteri(str, ft_example);
	printf("Después de ft_striteri: %s\n", str);

	return (0);
} */