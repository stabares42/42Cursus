/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:47:37 by stabares          #+#    #+#             */
/*   Updated: 2025/02/06 17:42:47 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

/* Función para ejecutar una prueba con un archivo específico */
void	run_test(const char *filename)
{
	int		fd;
	char	*line;
	int		line_number;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: No se pudo abrir el archivo %s\n", filename);
		return;
	}
	line_number = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Línea %d: %s", line_number++, line);
		free(line);
	}
	close(fd);
}

/* Función para probar el manejo de errores */
void	test_error_handling()
{
	char *line;

	printf("\nPrueba 7: Manejo de errores\n");
	printf("Prueba 7.1: Descriptor de archivo inválido\n");
	line = get_next_line(-1);
	if (line == NULL)
		printf("✔ Manejo de descriptor de archivo inválido correcto\n");
	else
	{
		printf("✖ Error: Se esperaba NULL para un descriptor de archivo inválido\n");
		free(line);
	}
}

int	main(void)
{
	printf("Prueba 1: Archivo vacío\n");
	run_test("test_gnl/empty.txt");

	printf("\nPrueba 2: Archivo con una sola línea\n");
	run_test("test_gnl/single_line.txt");

	printf("\nPrueba 3: Archivo con múltiples líneas\n");
	run_test("test_gnl/multiple_lines.txt");

	printf("\nPrueba 4: Archivo con líneas vacías\n");
	run_test("test_gnl/empty_lines.txt");

	printf("\nPrueba 5: Archivo con líneas muy largas\n");
	run_test("test_gnl/long_lines.txt");

	printf("\nPrueba 6: Archivo binario\n");
	run_test("test_gnl/binary_file.bin");

	test_error_handling();

	printf("\nPrueba 8: Archivo con combinaciones de saltos de línea\n");
	run_test("test_gnl/mixed_newlines.txt");

	printf("\nPrueba 9: Archivo grande\n");
	run_test("test_gnl/large_file.txt");

	return (0);
}
