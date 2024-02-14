/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:25:03 by diegmore          #+#    #+#             */
/*   Updated: 2023/09/06 20:12:59 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int main()
{
	char array[] = "";
	char array1[] = "";

	printf("%i : ft_strcmp \n", ft_strcmp(array, array1));
	printf("%i : strcpm \n", strcmp(array,array1));
	char array2[] = "dc";
	char array3[] = "";

	printf("%i : ft_strcmp \n", ft_strcmp(array2, array3));
	printf("%i : strcpm \n ", strcmp(array2,array3));
}
*/
