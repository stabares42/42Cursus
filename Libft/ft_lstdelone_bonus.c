/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:10:27 by stabares          #+#    #+#             */
/*   Updated: 2024/12/19 14:42:54 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}

/* void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*node;

	node = ft_lstnew("Contenido del nodo");

	printf("Antes de ft_lstdelone: %s\n", (char *)node->content);

	ft_lstdelone(node, del_content);

	if (!node)
		printf("Nodo eliminado correctamente.\n");

	return (0);
} */