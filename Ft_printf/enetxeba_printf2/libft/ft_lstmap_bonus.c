/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enetxeba <enetxeba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:44:43 by endika            #+#    #+#             */
/*   Updated: 2024/12/16 11:26:23 by enetxeba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*fun)(void *)
	, void (*del)(void *))
{
	t_list	*res;
	void	*cont;

	if (lst != NULL && fun != NULL && del != NULL)
	{
		cont = fun(lst->content);
		res = ft_lstnew(cont);
		if (res == NULL)
		{
			del(cont);
			return (NULL);
		}
		if (lst->next != NULL)
		{
			res->next = ft_lstmap(lst->next, fun, del);
			if (res->next == NULL)
			{
				ft_lstdelone(res, del);
				return (NULL);
			}
		}
		return (res);
	}
	return (NULL);
}
