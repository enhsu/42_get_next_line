/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:32:11 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 14:32:13 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s;

	i = ft_strlen(s1);
	s = (char*)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s = ft_memcpy(s, s1, i + 1);
	return (s);
}
