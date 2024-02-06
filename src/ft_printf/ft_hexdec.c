/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:53:40 by diegmore          #+#    #+#             */
/*   Updated: 2023/10/23 13:36:13 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_hexdec(unsigned long long int nbr, char *base)
{
	int	length;

	length = 0;
	if (nbr >= 16)
	{
		length += ft_hexdec((nbr / 16), base);
		length += ft_hexdec((nbr % 16), base);
	}
	else
	{
		write(1, &base[nbr], 1);
		length++;
	}
	return (length);
}
