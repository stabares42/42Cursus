/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:47:47 by stabares          #+#    #+#             */
/*   Updated: 2025/02/05 16:09:29 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buffer)
{
	char	*temp_buffer;
	ssize_t	byte_read;

	temp_buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(temp_buffer);
			return (NULL);
		}
		buffer = ft_strjoin(buffer, temp_buffer);
		if (ft_strchr(buffer, '\n'))
			break;
		if (byte_read = 0)
			break;
	}
	free(temp_buffer);
	return (buffer);
}
static char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i + 1);
	return (line);
}
static char *update_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;
	
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(ft_strlen(buffer) - i, sizeof(char));
	if (!new_buffer)
		return (NULL); 
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}