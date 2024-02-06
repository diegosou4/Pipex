/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:22:06 by diegmore          #+#    #+#             */
/*   Updated: 2023/10/16 22:24:43 by diemorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printc(const char *format, int i, int length, va_list list);
int	ft_strrchr(const char *str, int c);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_strlen(char *str);
int	ft_hexdec(unsigned long long int nbr, char *base);
int	ft_printp(unsigned long long int nbr);
int	ft_unsigned(unsigned int n);

#endif
