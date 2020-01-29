/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:59:38 by matraore          #+#    #+#             */
/*   Updated: 2019/10/24 01:01:47 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbr_word(char *str, char c)
{
	int i;
	int cmp;

	i = 0;
	cmp = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c) && (str[i + 1] == c || str[i + 1] == '\0'))
			cmp++;
		i++;
	}
	return (cmp);
}

static int		ft_nbr_char(char *str, char c)
{
	int i;
	int cmp;

	i = 0;
	cmp = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		cmp++;
	}
	return (cmp);
}

static void		allfree(char **str, int c)
{
	while (c >= 0)
	{
		free(str[c]);
		c--;
	}
	free(str);
}

static char		**spliter(char const *s1, char c)
{
	int		i;
	int		j;
	int		k;
	char	**word;

	i = -1;
	j = 0;
	if (!(word = (char **)malloc(sizeof(char *) *
					(ft_nbr_word((char *)s1, c) + 1))))
		return (0);
	while (++i < ft_nbr_word((char *)s1, c))
	{
		k = -1;
		while (((char *)s1)[j] == c)
			j++;
		if (!(word[i] = (char *)malloc(ft_nbr_char((char *)s1 + j, c) + 1)))
			allfree(word, i);
		while (((char *)s1)[j] != c && ((char *)s1)[j] != '\0')
			word[i][++k] = ((char *)s1)[j++];
		word[i][k + 1] = '\0';
	}
	word[i] = 0;
	return (word);
}

char			**ft_split(char const *s1, char c)
{
	if (!s1)
		return (0);
	return (spliter(s1, c));
}
