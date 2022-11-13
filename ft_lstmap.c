/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:14:53 by lfiorini          #+#    #+#             */
/*   Updated: 2022/11/13 17:57:49 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_valid(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head = ft_lstnew((*f)(lst->content));
	if (head == NULL)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	return (head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*head;
	t_list	*cur;

	head = ft_valid(lst, f, del);
	if (head == NULL)
		return (NULL);
	cur = lst->next;
	while (cur)
	{
		node = ft_lstnew((*f)(cur->content));
		if (node == NULL)
		{
			ft_lstclear(&head, del);
			ft_lstclear(&cur, del);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		cur = cur->next;
	}
	node = NULL;
	return (head);
}
