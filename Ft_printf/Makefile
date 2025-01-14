# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stabares <stabares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 21:17:08 by stabares          #+#    #+#              #
#    Updated: 2025/01/13 15:17:40 by stabares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ·Compilador y flags
CC = gcc
FLAG = -Wall -Werror -Wextra

# ·Archivos fuente y objetos
SRC = ft_printf.c ft_print_content.c
OBJ = $(SRC:.c=.o)

# ·Nombre de la biblioteca
NAME = libftprintf.a

# ·Librería libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# ·Incluir el archivo de cabecera
INCLUDE = ft_printf.h

# ·Archivos de objetos de la librería libft
LIBFT_OBJECTS = $(LIBFT_DIR)/*.o

# Regla principal: compila la librería libft y luego ft_printf
all: $(NAME)

# Compilación de la librería libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Regla para crear la biblioteca $(NAME) con los objetos $(OBJ)
$(NAME): $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ) $(LIBFT_OBJECTS)

# Regla para compilar los archivos fuente .c en objetos .o
%.o: %.c $(INCLUDE)
	$(CC) $(FLAG) -c $< -o $@

# Limpiar archivos objeto
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Limpieza completa
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Reconstruir todo
re: fclean all
