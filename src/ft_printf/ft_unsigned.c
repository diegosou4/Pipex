/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:33:41 by diegmore          #+#    #+#             */
/*   Updated: 2023/10/23 13:59:14 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_countwordls(unsigned int n)
{
	int	wordls;

	wordls = 0;
	if (n < 0)
	{
		wordls++;
		n *= -1;
	}
	if (n == 0)
		wordls++;
	while (n != 0)
	{
		n = n / 10;
		wordls++;
	}
	return (wordls);
}

int	ft_unsigned(unsigned int n)
{
	int	length;
	int	i;

	i = 0;
	length = ft_countwordls(n);
	if (n == 2147483648)
		return (ft_putstr("2147483648"));
	if (n > 9)
	{
		i = i + (n % 10);
		ft_unsigned(n / 10);
		i = i + '0';
		write(1, &i, 1);
		return (length);
	}
	else
	{
		n += '0';
		write(1, &n, 1);
	}
	return (length);
}
