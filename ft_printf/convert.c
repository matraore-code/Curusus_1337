/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 02:45:40 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 09:44:45 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*convert(unsigned int num, int base)
{
	static char	*representation;
	static char	buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	representation = ft_strdup("0123456789abcdef");
	*ptr = '\0';
	if (num == 0)
		*ptr = '0';
	else
	{
		while (num != 0)
		{
			*--ptr = representation[num % base];
			num /= base;
		}
	}
	return (ptr);
}

char	*convert_x(unsigned int num, int base)
{
	static char	*representation;
	static char	buffer[50];
	char		*ptr;

	representation = ft_strdup("0123456789ABCDEF");
	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*ptr = '0';
	else
	{
		while (num != 0)
		{
			*--ptr = representation[num % base];
			num /= base;
		}
	}
	return (ptr);
}
