/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:43:43 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 14:44:37 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rs;

	if (!s1 || !s2)
		return (NULL);
	rs = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!rs)
		return (NULL);
	rs = ft_strcat(rs, s1);
	rs = ft_strcat(rs, s2);
	return (rs);
}
