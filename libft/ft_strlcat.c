/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:32:52 by chsu              #+#    #+#             */
/*   Updated: 2018/10/26 16:53:02 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dl;
	size_t	i;
	size_t	j;

	dl = ft_strlen(dst);
	i = dl;
	j = 0;
	if (dstsize < dl + 1)
		return (ft_strlen(src) + dstsize);
	while (j < dstsize - dl - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dl + ft_strlen(src));
}
