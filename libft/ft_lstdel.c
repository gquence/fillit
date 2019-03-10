/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:03:43 by gquence           #+#    #+#             */
/*   Updated: 2019/02/17 18:30:51 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*node;

	if (!alst || !*alst || !del)
		return ;
	node = *alst;
	while (node)
	{
		del(node->content, node->content_size);
		free(node);
		node = node->next;
	}
	*alst = NULL;
}
