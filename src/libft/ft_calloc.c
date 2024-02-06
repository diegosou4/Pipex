/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:03:57 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/06 18:03:59 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	result;

	result = nmemb * size;
	if (nmemb == 0 && size == 0)
		p = (void *)malloc(1);
	p = (void *)malloc(result);
	if (!p)
		return (0);
	p = ft_bzero(p, result);
	if (!p)
	{
		return (0);
	}
	return (p);
}