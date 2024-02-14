/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:20:09 by diegmore          #+#    #+#             */
/*   Updated: 2024/02/14 17:20:11 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*subs;
	char	*subre;

	if (!s)
		return (NULL);
	len_s = ft_strlen((char *)s);
	i = 0;
	subs = (char *)ft_calloc((len + 1), sizeof(char));
	if (!subs)
		return (NULL);
	while (i < len && start < len_s)
	{
		subs[i] = s[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	subre = ft_strdup(subs);
	free(subs);
	return (subre);
}
