/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:57:58 by stabares          #+#    #+#             */
/*   Updated: 2024/12/03 15:58:00 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Check functions
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

// String functions
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *str, int c);

// Memory manipulation functions
void		*ft_memset(void *b, int c, size_t n);
void		ft_bzero(void *b, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_memmove(void *dest, const void *src, size_t n);

// Character manipulations functions
int			ft_toupper(int c);
int			ft_tolower(char c);

#endif