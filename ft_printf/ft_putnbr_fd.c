/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:50:15 by matraore          #+#    #+#             */
/*   Updated: 2019/10/17 13:35:24 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long n)
{
	long	nbr;
	int		mod;

	nbr = n;
	mod = 0;
	if (n < 10 && n >= 0)
		ft_putchar_fd(n + 48);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648");
	else if (n < 0)
	{
		ft_putchar_fd('-');
		ft_putnbr((n * -1));
	}
	else
	{
		mod = nbr % 10;
		nbr = nbr / 10;
		ft_putnbr(nbr);
		ft_putchar_fd((mod + 48));
	}
}
