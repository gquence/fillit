/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:35:51 by gquence           #+#    #+#             */
/*   Updated: 2019/03/03 16:17:23 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_get_line(t_list **plst, char **line)
{
	t_list			*lst;
	char			*content;
	size_t			len;
	size_t			len_n;

	if (!plst || !*plst || !(char *)((*plst)->content) ||
	!*(char *)((*plst)->content) || !(len = ft_strlen((char *)(*plst)->content)))
		return (0);
	lst = *plst;
	content = (char *)(lst->content);
	len_n = 0;
	while (*(content + len_n) && *(content + len_n) != '\n')
		len_n++;
	if (len_n == len)
	{
		*line = content;
		(lst->content) = (void *)ft_strnew(0);
		return (1);
	}
	*line = ft_strsub(content, 0, len_n);
	(lst->content) = ft_strsub(content, len_n + 1, (len - len_n));
	free(content);
	return (1);
	
}

static	t_list		*ft_corr_file(t_list **file, const int fd)
{
	t_list			*lst;

	if (fd < 0 || !file)
		return (NULL);
	if (!*file)
		return (*file = ft_lstnew("", fd));
	lst = *file;
	while (lst)
	{
		if (lst->content_size == (size_t)fd && ((char *)lst->content))
			return (lst);
		lst = lst->next;
	}
	lst = ft_lstnew("", fd);
	ft_lstadd(file, lst);
	lst = *file;
	return (lst);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*curr;
	char			*content;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || (BUFF_SIZE < 1) ||
		!(curr = ft_corr_file(&file, fd)))
		return (-1);
	if ((ft_strchr((char*)(curr->content),'\n')) && ft_get_line(&curr, line))
		return (1);
	while ((ret = read(fd, &buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = 0;
		content = (char *)(curr->content);
		curr->content = (char *)ft_strjoin((char *)(curr->content), buf);
		free(content);
		if (ret != BUFF_SIZE || ft_strchr((char *)(curr->content), '\n'))
			break ;
	}
	return (ft_get_line(&curr, line));
}
