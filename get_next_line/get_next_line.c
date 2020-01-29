/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:11:50 by matraore          #+#    #+#             */
/*   Updated: 2019/11/20 02:42:35 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_free(char **str, char *str1, int ret)
{
	free(*str);
	free(str1);
	return (ret);
}

int		ft_line(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		if (!(*line = ft_substr(*s, 0, len)))
			return (ft_free(s, NULL, -1));
		tmp = *s;
		if (!(*s = ft_strdup(&((*s)[len + 1]))))
			return (ft_free(s, tmp, -1));
		free(tmp);
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(*s)))
			return (ft_free(s, NULL, -1));
		free(*s);
		*s = NULL;
		return (0);
	}
}

int		ft_rendu(char **s, char **line, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && *s == NULL)
		return (0);
	else
		return (ft_line(s, line));
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*s;
	char		*buff;
	char		*tmp;

	if (fd < 0 || !line || read(fd, NULL, 0) != 0)
		return (-1);
	if (!s)
		s = ft_strdup("");
	if (!(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = s;
		if (!(s = ft_strjoin(s, buff)))
			return (-1);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(s, '\n'))
			break ;
	}
	free(buff);
	return (ft_rendu(&s, line, ret));
}
