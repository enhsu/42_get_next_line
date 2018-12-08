/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:33:08 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 14:33:09 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	nl;

	i = 0;
	nl = ft_strlen(needle);
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		if (haystack[i] == *needle)
			if (ft_memcmp((haystack + i), needle, nl) == 0)
				return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
