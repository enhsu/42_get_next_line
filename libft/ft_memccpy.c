/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:31:28 by chsu              #+#    #+#             */
/*   Updated: 2018/10/26 16:57:39 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(
		void *dst,
		const void *src,
		int c,
		size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
