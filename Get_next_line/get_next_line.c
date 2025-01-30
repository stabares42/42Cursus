/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:32:29 by stabares          #+#    #+#             */
/*   Updated: 2025/01/30 17:52:05 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_to_buffer(int fd, char **buffer)
{
	char	*temp_buffer;
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
	*buffer = ft_strjoin(*buffer, temp_buffer);
	free(temp_buffer);
	return (1);
}
static char	*extrac_line(char **buffer)
{
	char	*line;
	char	*newline_pos;
	size_t	line_len;

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
	return (line);
}
static void	update_buffer(char **buffer)
{
	char	*newline_pos;
	char	*new_buffer;

	newline_pos = ft_strchr(*buffer, '\n');
	if (!newline_pos)
	{
		free(*buffer);
		*buffer = NULL;
		return ;
	}
	new_buffer = ft_strdup(newline_pos + 1);
	free(*buffer);
	*buffer = new_buffer;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (read_to_buffer(fd, &buffer))
		return (NULL);
	line = extract_line(&buffer);
	update_buffer(&buffer);
	return (NULL);
}
