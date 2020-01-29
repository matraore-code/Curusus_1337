/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:40:32 by matraore          #+#    #+#             */
/*   Updated: 2019/10/18 16:11:05 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = 0;
	if (s)
	{
		j = ft_strlen((char *)s) + 1;
		str = (char *)malloc(j * sizeof(char));
		if (str == NULL)
			return (0);
		while (i < j - 1)
		{
			str[i] = f(i, ((char *)s)[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
