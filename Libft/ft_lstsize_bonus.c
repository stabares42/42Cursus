/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:16:19 by stabares          #+#    #+#             */
/*   Updated: 2024/12/17 12:53:33 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst -> next;
	}
	return (size);
}

/* int	main(void)
{
	t_list	node1;
	t_list	node2;
	t_list	node3;

	node1.content = "Nodo 1";
	node1.next = &node2;
	node2.content = "Nodo 2";
	node2.next = &node3;
	node3.content = "Nodo 3";
	node3.next = NULL;

	printf("Tamaño de la lista: %d\n", ft_lstsize(&node1));
	return (0);
} */