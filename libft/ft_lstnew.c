/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:57:16 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 14:58:09 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list*)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	if (!content)
	{
		elem->content = NULL;
		elem->content_size = 0;
		return (elem);
	}
	elem->content = malloc(sizeof(*content) * content_size);
	if (!elem->content)
		return (NULL);
	elem->content = ft_memcpy(elem->content, content, content_size);
	elem->content_size = content_size;
	return (elem);
}
