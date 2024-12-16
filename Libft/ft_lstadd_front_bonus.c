/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:02:51 by stabares          #+#    #+#             */
/*   Updated: 2024/12/16 14:27:17 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

/* int	main(void)
{
	t_list	*node1;
	t_list	*new_node;
	char	*content1 = "Hola, mundo";
	char	*new_content = "Nuevo nodo";

	node1 = ft_lstnew(content1);

	new_node = ft_lstnew(new_content);

	ft_lstadd_front(&node1, new_node);

	printf("Contenido del primer nodo: %s\n", (char *)node1->content);

	return (0);
} */