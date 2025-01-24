/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:02:24 by stabares          #+#    #+#             */
/*   Updated: 2025/01/24 17:47:57 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


// Lee del archivo y acumula el contenido en un buffer dinámico temporal.
static char	*read_to_buffer(int fd, char *remaining_content)
{
	char	*buffer;
	ssize_t	byte_read;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (byte_read <= 0)
		{
			free(buffer);
			return (remaining_content);
		}
	buffer[byte_read] = '\0';
	temp = ft_strjoin(remaining_content, buffer);
	free(buffer);
	free(remaining_content);
	return (temp);
}

// Extrae la línea hasta el prime salto de linea '\n' y actualiza el buffer.
static char	*extract_line_from_buffer(char **remaining_content)
{
	
}



char	*get_next_line(int fd)
{
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	size_t	line_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	line_size = find_newline(buffer, bytes_read);
	line = malloc(line_size + 1);
	if (!line)
		return (NULL);
	copy_to_line(line, buffer, line_size);
	return (line);
}
