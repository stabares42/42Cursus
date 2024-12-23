/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enetxeba <enetxeba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:24:08 by enetxeba          #+#    #+#             */
/*   Updated: 2024/12/16 10:47:50 by enetxeba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	c;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if ((start + len) >= (size_t) s_len)
		len = s_len - start;
	if (start >= s_len)
		len = 0;
	res = (char *) malloc (sizeof(*s) * (len + 1));
	if (res == NULL)
		return (NULL);
	c = 0;
	while (c < len)
	{
		res[c] = s[start + c];
		c++;
	}
	res[c] = '\0';
	return (res);
}

/* #include <stdio.h>
int main ()
{
	char *c;
	
	c = ft_substr("HOLA MUNDO", 8, 5);
	printf ("a %zu", ft_strlen (c));
} */