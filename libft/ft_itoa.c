/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:36:19 by matraore          #+#    #+#             */
/*   Updated: 2019/10/22 20:55:43 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size(int nb)
{
	int r;

	r = 0;
	if (nb <= 0)
	{
		r++;
		nb = -1 * nb;
	}
	while (nb != 0)
	{
		r++;
		nb = nb / 10;
	}
	return (r);
}

char	*ft_fill_str(char *str, long long int n, int len)
{
	int l;
	int deb;

	deb = 0;
	len = ft_size(n);
	l = len;
	if (n < 0)
	{
		str[0] = '-';
		deb = 1;
		n *= -1;
	}
	while (len - 1 >= deb)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	str[l] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(ft_size(n) + 1);
	if (str == NULL)
		return (0);
	return (ft_fill_str(str, n, i));
}
