/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:15:09 by stabares          #+#    #+#             */
/*   Updated: 2025/02/05 17:43:14 by stabares         ###   ########.fr       */
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

char	ft_strchr(const char *str, char c)
{
	while (str && *str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	size_t	len_str1;
	size_t	len_str2;
	size_t	i;
	size_t	j;

	if (!str2)
		return (str1);
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	result = ft_calloc((len_str1 + len_str2 + 1), sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str1 && str1[j])
		result[i++] = str1[j++];
	if (str1)
		free(str1);
	j =  0;
	while (str2[j])
		result[i++] = str2[j++];
	return (result);
}

char *ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_calloc(1, sizeof(char)));
	if (len > str_len - start)
		len = str_len - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = str[start + i];
		i++;
	}
	return (sub);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;
	size_t i;
	
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
		((char *)ptr)[i++] = '\0';
	return (ptr);
}