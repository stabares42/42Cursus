/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:57:58 by stabares          #+#    #+#             */
/*   Updated: 2024/12/10 18:36:32 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

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
char		*ft_strrchr(const char *str, char c);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *str1, const char *str2, size_t n);

// Memory manipulation functions
void		*ft_memset(void *b, int c, size_t n);
void		ft_bzero(void *b, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *str, int ch, size_t n);
void		*ft_calloc(size_t n_elemts, size_t size);
void		*ft_calloc(size_t nmemb, size_t size);

// Character manipulations functions
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *str);

#endif