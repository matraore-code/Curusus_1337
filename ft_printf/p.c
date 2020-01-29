/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 03:22:13 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 10:22:16 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

char			*convert_p(size_t num, int base)
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

static size_t	get_num(t_tab *tab)
{
	size_t	num;

	num = va_arg(tab->args, size_t);
	return (num);
}

static t_tab	*print_u(t_tab *tab, char *str, int align_left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	tab->len += (not_blank <= tab->width) ? tab->width : not_blank;
	if (!align_left)
		get_display(tab, ' ', tab->width - not_blank, 0);
	write(1, "0x", 2);
	get_display(tab, '0', (tab->precision - num_width) + 2, 1);
	ft_putstr_fd(str);
	if (align_left)
		get_display(tab, ' ', tab->width - not_blank, 0);
	return (tab);
}

t_tab			*d_pvoid(t_tab *tab)
{
	char		*str;
	size_t		num;
	int			align_left;

	align_left = 0;
	num = get_num(tab);
	str = convert_p(num, 16);
	if (tab->flags[0] == '-')
		align_left = 1;
	if (tab->precision == 0 && num == 0)
		*str = '\0';
	if (tab->flags[1] == '0' && tab->precision == -1 && !tab->flags[0])
	{
		tab->precision = tab->width - 2;
		tab->width = 0;
	}
	print_u(tab, str, align_left);
	return (tab);
}
