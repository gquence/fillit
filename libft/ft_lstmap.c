/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:04:05 by gquence           #+#    #+#             */
/*   Updated: 2019/02/17 18:32:52 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*node_buf;

	if (!f || !lst)
		return (NULL);
	node = f(lst);
	node_buf = node;
	while (lst->next)
	{
		lst = lst->next;
		if (!(node->next = f(lst)))
		{
			while ((node_buf = node_buf->next))
			{
				free(node_buf->content);
				free(node_buf);
			}
			return (NULL);
		}
		node = node->next;
	}
	return (node_buf);
}
