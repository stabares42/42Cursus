/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endika <endika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 07:23:18 by endika            #+#    #+#             */
/*   Updated: 2024/12/01 19:01:15 by endika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*list_memb;

	list_memb = malloc (sizeof(t_list));
	if (list_memb == NULL)
		return (NULL);
	list_memb->content = content;
	list_memb->next = NULL;
	return (list_memb);
}
