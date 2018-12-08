/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:46:18 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 14:46:39 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ia_get_nb_l(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while ((n /= 10) > 0)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*rs;
	int		nl_pon[2];

	nl_pon[0] = ia_get_nb_l(n);
	nl_pon[1] = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		n *= -1;
		nl_pon[1] = -1;
	}
	rs = (char*)malloc(sizeof(*rs) * (nl_pon[0] + 1));
	if (!rs)
		return (NULL);
	rs[nl_pon[0]] = '\0';
	while (nl_pon[0] > 0)
	{
		rs[nl_pon[0] - 1] = n % 10 + '0';
		n /= 10;
		nl_pon[0] -= 1;
	}
	if (nl_pon[1] == -1)
		rs[0] = '-';
	return (rs);
}
