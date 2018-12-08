/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:10:36 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 15:10:39 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *alst)
{
	size_t	num;
	t_list	*head;

	num = 0;
	head = alst;
	if (!head)
		return (num);
	while (head)
	{
		++num;
		head = head->next;
	}
	return (num);
}
