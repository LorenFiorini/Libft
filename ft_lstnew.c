/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorini <lfiorini@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:52:51 by lfiorini          #+#    #+#             */
/*   Updated: 2022/10/20 10:23:58 by lfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
