/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:33:15 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 15:10:09 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nl;

	i = 0;
	nl = ft_strlen(needle);
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == *needle)
			if (i + nl <= len)
				if (ft_memcmp((haystack + i), needle, nl) == 0)
					return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
