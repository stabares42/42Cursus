/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:00:50 by stabares          #+#    #+#             */
/*   Updated: 2024/12/19 14:44:10 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	list = ft_lstlast(*lst);
	list -> next = new;
}

/* int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;

	// Crear los nodos
	node1 = ft_lstnew("Primer nodo");
	node2 = ft_lstnew("Segundo nodo");

	// Lista vacía al principio
	head = NULL;

	// Añadir el primer nodo
	ft_lstadd_back(&head, node1);
	printf("Lista después de agregar el primer nodo: %s\n", (char *)head->content);

	// Añadir el segundo nodo
	ft_lstadd_back(&head, node2);
	printf("Lista después de agregar el segundo nodo: %s\n", (char *)head->next->content);

	return (0);
} */