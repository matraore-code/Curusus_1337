/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:43:15 by matraore          #+#    #+#             */
/*   Updated: 2019/10/24 01:41:03 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_detect(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		deb;
	int		fin;
	int		i;
	char	*str;

	if (!s1)
		return (0);
	i = -1;
	fin = ft_strlen((char *)s1) - 1;
	deb = 0;
	str = 0;
	while (ft_detect((char *)set, s1[deb]))
		deb++;
	while (ft_detect((char *)set, s1[fin]))
		fin--;
	if (fin < deb)
		return (ft_strdup(""));
	str = (char *)malloc(fin - deb + 2);
	if (str == NULL)
		return (0);
	while (++i + deb <= fin)
		str[i] = ((char *)s1)[deb + i];
	str[i] = '\0';
	return (str);
}
