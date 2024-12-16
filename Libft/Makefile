# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stabares <stabares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 15:47:57 by stabares          #+#    #+#              #
#    Updated: 2024/12/16 16:43:30 by stabares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs

RM = rm -fr

CC = gcc

CCFlAGS = -Wall -Werror -Wextra

 
NAME = libft.a

SRC_IS = ft_isalpha.c		\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c

SRC_STR = ft_strlen.c		\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_strjoin.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_substr.c		\
			ft_strtrim.c	\
			ft_split.c		\
			ft_strmapi.c	\
			ft_striteri.c
			
SRC_PUT = ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\

SRC_MEM = ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_calloc.c		\
			ft_memchr.c		\
			ft_memcmp.c		\

SRC_TO = ft_toupper.c		\
			ft_tolower.c	\
			ft_atoi.c		\
			ft_itoa.c

SRC_BONUS = ft_lstadd_front_bonus.c	\
			ft_lstnew_bonus.c		\
			ft_lstsize_bonus.c		\
			

SRC = $(SRC_IS) $(SRC_STR) $(SRC_PUT) $(SRC_MEM) $(SRC_TO)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFlAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re