/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:44:48 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 14:45:34 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	if (i == ft_strlen(s))
		j = i;
	else
	{
		while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && (j > 0))
			j--;
	}
	return (ft_strsub(s, i, (j - i + 1)));
}
