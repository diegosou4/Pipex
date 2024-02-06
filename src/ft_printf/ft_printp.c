/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:10:47 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/06 17:10:48 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printp(unsigned long long int nbr)
{
	int	length;

	length = 0;
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return ((length += 5));
	}
	write(1, "0x", 2);
	return ((length += ft_hexdec(nbr, "0123456789abcdef") + 2));
}
