/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:10:35 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/06 17:10:37 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		length;
	int		i;

	va_start(list, format);
	i = 0;
	length = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strrchr("cspdiuxX%", format[i + 1]))
		{
			length = ft_printc(format, i, length, list);
			i++;
		}
		else
		{
			length += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(list);
	return (length);
}
