/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enetxeba <enetxeba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:27:23 by endika            #+#    #+#             */
/*   Updated: 2024/12/16 11:03:19 by enetxeba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur_nod_ptr;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		cur_nod_ptr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = cur_nod_ptr;
	}
}
