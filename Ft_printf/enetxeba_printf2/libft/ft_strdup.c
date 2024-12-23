/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endika <endika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:53:08 by enetxeba          #+#    #+#             */
/*   Updated: 2024/11/29 12:02:19 by endika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	size_t	c;

	len = ft_strlen(s);
	ptr = malloc(len + 1);
	c = 0;
	if (ptr == NULL)
		return (NULL);
	while (c < len)
	{
		*(ptr + c) = *(s + c);
		c++;
	}
	*(ptr + len) = '\0';
	return (ptr);
}
