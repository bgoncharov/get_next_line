/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:25:14 by bogoncha          #+#    #+#             */
/*   Updated: 2019/03/05 14:56:27 by bogoncha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					check_res(int fd, char **text, char **line)
{
	int				len;
	char			*tmp;

	len = 0;
	while (text[fd][len] != '\n' && text[fd][len] != '\0')
		len++;
	if (text[fd][len] == '\n')
	{
		*line = ft_strsub(text[fd], 0, len);
		tmp = ft_strdup(&text[fd][len + 1]);
		ft_strdel(&text[fd]);
		text[fd] = tmp;
	}
	else
	{
		*line = ft_strdup(text[fd]);
		ft_strdel(&text[fd]);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char			*tmp;
	char			buff[BUFF_SIZE + 1];
	static char		*text[MAX_FD];
	int				ret;

	if (fd < 0 || !line || (read(fd, buff, 0) < 0) || \
		fd > MAX_FD || BUFF_SIZE <= 0)
		return (-1);
	if (!text[fd])
		text[fd] = ft_strnew(1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(text[fd], buff);
		ft_strdel(&text[fd]);
		text[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (text[fd][0] == '\0')
		return (0);
	return (check_res(fd, text, line));
}
