/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:48:52 by stabares          #+#    #+#             */
/*   Updated: 2024/12/19 14:32:59 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof (char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* char	ft_transform(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	char	*resultado;

	resultado = ft_strmapi("abcd", ft_transform);
	printf("Resultado: %s\n", resultado);
	free(resultado);
	return (0);
} */