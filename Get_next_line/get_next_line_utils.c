/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:32:36 by stabares          #+#    #+#             */
/*   Updated: 2025/01/28 17:33:41 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;
	
	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
	
}


char	*ft_strchr(const char *str, int c)
{
	size_t i;

	if (!str)
		return (NULL);
	i = 0;
	while(str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (str[i]);
	return (NULL);
}

void	ft_strcpy(const char *src, char *dest)
{
	size_t	i;
	
	i = 0;
	while (src[i] != '\0' && src[i] != '\n')
		dest[i++] = *src++;
}

void *ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	i;
	
	p = malloc(nmemb * size);
	if (!p)
		return (0);
	i = 0;
	while (i < nmemb)
		((char *)p)[i++] = '\0';
	return (p);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	size_t	len_str1;
	size_t	len_str2;
	size_t	i;

	if (!str2)
		return (str1);
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	result = ft_calloc((len_str1 + len_str2 + 1), sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	if (!str1)
	{
		ft_strcpy(str2, result);
		return (result);
	}
	ft_strcpy(str1, result);
	ft_strcpy(str2, result);
	free(str1);
	return (result);
}
