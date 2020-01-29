/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:05:37 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 10:08:59 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	*fmt(void *dest, int val, size_t len)
{
	unsigned char *ptr;

	ptr = dest;
	while (len-- > 0)
		*ptr++ = val;
	return (dest);
}

char	*get(int len)
{
	char	*str;
	int		j;

	j = 0;
	len *= (len < 0) ? 0 : 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (j < (len + 1))
	{
		str[j] = '\0';
		j++;
	}
	return (str);
}

void	get_display(t_tab *tab, char c, int len, int update_len)
{
	char	*str;

	len *= (len < 0) ? 0 : 1;
	str = get(len);
	if (len >= 0)
	{
		if (update_len)
			tab->len += len;
		fmt(str, c, len);
		write(1, str, len);
		free(str);
	}
}
