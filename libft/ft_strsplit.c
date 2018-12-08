/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:45:43 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 15:06:26 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sp_get_word_nb(char const *s, char c)
{
	size_t	i;
	size_t	wn;

	i = 0;
	wn = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c && s[i]))
			wn++;
		i++;
	}
	return (wn);
}

static int	sp_get_word_l(char const *s, char c, size_t wo)
{
	size_t	i;
	size_t	cw;
	size_t	wl;

	i = 0;
	cw = 0;
	wl = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c && s[i]))
			cw++;
		if (cw - 1 == wo)
		{
			while (s[i + wl] != c && s[i + wl])
				wl++;
			break ;
		}
		i++;
	}
	return (wl);
}

static char	*sp_get_word(char const *s, char c, size_t wo, char *dst)
{
	size_t	i;
	size_t	cw;
	size_t	wl;

	i = 0;
	cw = 0;
	wl = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c && s[i]))
			cw++;
		if (cw - 1 == wo)
		{
			while (s[i + wl] != c && s[i + wl])
				wl++;
			dst = ft_strsub(s, i, wl);
			break ;
		}
		i++;
	}
	return (dst);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**re_arr;
	size_t	wn;
	size_t	wo;

	if (!s)
		return (NULL);
	wn = sp_get_word_nb(s, c);
	re_arr = (char**)malloc(sizeof(*re_arr) * (wn + 1));
	if (!re_arr)
		return (NULL);
	wo = 0;
	while (wo < wn)
	{
		re_arr[wo] = (char*)malloc(sizeof(**re_arr) *
				(sp_get_word_l(s, c, wo) + 1));
		if (!re_arr[wo])
			return (NULL);
		re_arr[wo] = sp_get_word(s, c, wo, re_arr[wo]);
		wo++;
	}
	re_arr[wo] = 0;
	return (re_arr);
}
