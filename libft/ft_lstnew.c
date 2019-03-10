/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:23:40 by gquence           #+#    #+#             */
/*   Updated: 2019/03/02 15:58:21 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;
	void	*new_cont;

	if (!(new_cont = ft_memalloc(content_size + 1)))
		return (NULL);
	if (!content)
	{
		new_cont = NULL;
		content_size = 0;
	}
	else
		ft_memcpy(new_cont, content, content_size);
	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	node->content = new_cont;
	node->content_size = content_size;
	node->next = NULL;
	return (node);
}
