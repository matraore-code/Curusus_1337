/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:54:59 by matraore          #+#    #+#             */
/*   Updated: 2019/10/23 17:50:03 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	unsigned int i;
	unsigned int j;

	if (!str1 && len == 0 && str2)
		return (NULL);
	if (*str2 == '\0')
		return ((char*)str1);
	i = 0;
	while (str1[i] && i < len)
	{
		j = 0;
		while (str1[i + j] && i + j < len && str2[j] && str1[i + j] == str2[j])
			j++;
		if (str2[j] == '\0')
			return ((char *)(str1 + i));
		i++;
	}
	return (NULL);
}
