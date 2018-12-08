/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:07:45 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 15:07:57 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*pre;
	t_list	*cur;
	t_list	*nxt;

	pre = NULL;
	cur = *alst;
	while (cur)
	{
		nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
	}
	*alst = pre;
}
