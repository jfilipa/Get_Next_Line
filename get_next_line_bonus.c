/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfilipa- <jfilipa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:43:04 by jfilipa-          #+#    #+#             */
/*   Updated: 2024/01/02 21:43:04 by jfilipa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (FOPEN_MAX <= fd || BUFFER_SIZE <= 0 || fd < 0)
	{
		if (fd > 0 && fd < FOPEN_MAX)
			while (buffer[fd][i])
				buffer[fd][i++] = '\0';
		return (NULL);
	}
	line = NULL;
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (!line)
			return (NULL);
		ft_clean_buffer(buffer[fd]);
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
		if (read(fd, buffer[fd], BUFFER_SIZE) < 0)
			return (free (line), NULL);
	}
	return (line);
}
