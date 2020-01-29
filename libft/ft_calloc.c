/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:19:52 by matraore          #+#    #+#             */
/*   Updated: 2019/10/23 17:38:53 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	i;
	void			*str;

	i = 0;
	str = malloc(nmemb * size);
	if (str == NULL)
		return (0);
	ft_bzero(str, nmemb * size);
	return (str);
}
