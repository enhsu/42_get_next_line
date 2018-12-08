/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:57:00 by chsu              #+#    #+#             */
/*   Updated: 2018/10/24 14:57:05 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	cp_n;
	int	n_size;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	cp_n = n;
	n_size = 1;
	while ((cp_n /= 10) > 0)
		n_size *= 10;
	while (n_size > 0)
	{
		ft_putchar_fd((n / n_size) + '0', fd);
		n %= n_size;
		n_size /= 10;
	}
}
