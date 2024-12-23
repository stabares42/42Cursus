/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enetxeba <enetxeba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:06 by enetxeba          #+#    #+#             */
/*   Updated: 2024/12/16 10:04:41 by enetxeba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*ret;
	size_t	x;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ret = ft_calloc(sizeof(char), len + 1);
	if (!ret)
		return (NULL);
	x = 0;
	while (x < len)
	{
		ret[x] = f(x, s[x]);
		x++;
	}
	ret[x] = '\0';
	return (ret);
}
