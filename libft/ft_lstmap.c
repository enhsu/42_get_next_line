/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:00:20 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 15:00:40 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*rl;
	t_list	*head;

	if (!lst)
		return (NULL);
	head = (*f)(lst);
	rl = head;
	while (lst->next)
	{
		head->next = (*f)(lst->next);
		head = head->next;
		lst = lst->next;
	}
	return (rl);
}
