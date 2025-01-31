/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:32:29 by stabares          #+#    #+#             */
/*   Updated: 2025/01/31 16:09:52 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_to_buffer(int fd, char **buffer)
{
	char	*temp_buffer;
	char	*temp;
	ssize_t	bytes_read;

	temp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_buffer)
		return (0);
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(temp_buffer);
		return (bytes_read == 0);
	}
	temp_buffer[bytes_read] = '\0';
	temp = ft_strjoin(*buffer, temp_buffer);
	free(temp_buffer);
	free(temp);
	*buffer = temp;
	return (1);
}
static char	*extrac_line(char **buffer)
{
	char	*line;
	char	*newline_pos;
	size_t	line_len;

	if (!*buffer || !**buffer)
		return (NULL);
	newline_pos = ft_strchr(*buffer, '\n');
	if (!newline_pos)
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (line);
	}
	line_len = newline_pos - *buffer + 1;
	line = ft_substr(*buffer, 0, line_len);
	newline_pos = ft_strdup(newline_pos + 1);
	free(*buffer);
	*buffer = newline_pos;
	return (line);
}
char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	len;
	size_t	i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	dup = ft_calloc(len + 1, sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!read_to_buffer(fd, &buffer))
		return (NULL);
	line = extrac_line(&buffer);
	return (line);
}
