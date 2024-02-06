/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:22:45 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/06 18:22:47 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);
	new = (char *)malloc(((size_s1 + size_s2) + (1)) * sizeof(char));
	if (!new || (!s1 && !s2))
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}