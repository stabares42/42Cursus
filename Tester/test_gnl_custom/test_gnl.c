/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:47:37 by stabares          #+#    #+#             */
/*   Updated: 2025/02/12 13:53:44 by stabares         ###   ########.fr       */
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

/* Función para probar la lectura de varios archivos simultáneamente */
void	test_multiple_files()
{
	int		fd1, fd2, fd3;
	char	*line1, *line2, *line3;
	int		line_number;

	printf("\nPrueba 10: Lectura de varios archivos simultáneamente\n");

	fd1 = open("test_gnl/multiple_lines.txt", O_RDONLY);
	fd2 = open("test_gnl/empty_lines.txt", O_RDONLY);
	fd3 = open("test_gnl/long_lines.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		printf("Error: No se pudieron abrir los archivos\n");
		return;
	}

	line_number = 1;
	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);

		if (!line1 && !line2 && !line3)
			break;

		if (line1)
		{
			printf("Archivo 1 - Línea %d: %s", line_number, line1);
			free(line1);
		}
		if (line2)
		{
			printf("Archivo 2 - Línea %d: %s", line_number, line2);
			free(line2);
		}
		if (line3)
		{
			printf("Archivo 3 - Línea %d: %s", line_number, line3);
			free(line3);
		}
		line_number++;
	}

	close(fd1);
	close(fd2);
	close(fd3);
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

	printf("Prueba 7.2: Archivo inexistente\n");
	line = get_next_line(open("test_gnl/nonexistent_file.txt", O_RDONLY));
	if (line == NULL)
		printf("✔ Manejo de archivo inexistente correcto\n");
	else
	{
		printf("✖ Error: Se esperaba NULL para un archivo inexistente\n");
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

	printf("\nPrueba 11: Archivo con solo un salto de línea\n");
	run_test("test_gnl/single_newline.txt");

	printf("\nPrueba 12: Archivo con múltiples saltos de línea consecutivos\n");
	run_test("test_gnl/multiple_consecutive_newlines.txt");

	printf("\nPrueba 13: Archivo con caracteres especiales\n");
	run_test("test_gnl/special_characters.txt");

	printf("\nPrueba 14: Archivo con líneas de diferentes longitudes\n");
	run_test("test_gnl/varying_line_lengths.txt");

	printf("\nPrueba 15: Archivo con líneas extremadamente largas\n");
	run_test("test_gnl/extremely_long_lines.txt");

	printf("\nPrueba 16: Archivo con combinaciones complejas de saltos de línea\n");
	run_test("test_gnl/complex_newlines.txt");

	test_multiple_files();

	return (0);
}