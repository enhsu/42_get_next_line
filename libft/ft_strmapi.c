/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:40:56 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 14:41:04 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rs;
	size_t	i;

	if (!s || !f)
		return (NULL);
	rs = ft_strnew(ft_strlen(s));
	if (!rs)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rs[i] = (*f)(i, s[i]);
		i++;
	}
	rs[i] = '\0';
	return (rs);
}
