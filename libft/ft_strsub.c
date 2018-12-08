/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:41:40 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 14:43:35 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*rs;

	if (!s)
		return (NULL);
	rs = ft_strnew(len);
	if (!rs)
		return (NULL);
	rs = ft_strncpy(rs, &(s[start]), len);
	return (rs);
}
