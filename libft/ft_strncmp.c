/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:33:32 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 15:11:09 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1v;
	unsigned char	*s2v;
	size_t			i;

	s1v = (unsigned char*)s1;
	s2v = (unsigned char*)s2;
	i = 0;
	while (i < n && s1v[i])
	{
		if (s1v[i] != s2v[i])
			return (s1v[i] - s2v[i]);
		i++;
	}
	if (i != n)
		return (s1v[i] - s2v[i]);
	return (0);
}
