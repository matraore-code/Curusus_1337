/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:15:16 by matraore          #+#    #+#             */
/*   Updated: 2019/10/24 00:05:01 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[len] = '\0';
	return (str);
}
