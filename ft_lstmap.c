/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:14:53 by lfiorini          #+#    #+#             */
/*   Updated: 2022/11/13 12:15:08 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*head;
	t_list	*cur;

	head = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	if ((node = ft_lstnew(f(lst->content))) == NULL)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	head = node;
	cur = lst->next;
	while (cur)
	{
		node = ft_lstnew(f(cur->content));
		if (node == NULL)
		{
			ft_lstclear(&head, del);
			ft_lstclear(&lst, del);
			//free(node);
			//cur = NULL;
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		cur = cur->next;
	}
	node = NULL;
	return (head);
}
