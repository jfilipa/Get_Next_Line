/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfilipa- <jfilipa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:44:01 by jfilipa-          #+#    #+#             */
/*   Updated: 2023/12/28 00:44:01 by jfilipa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		while (i <= BUFFER_SIZE)
			buffer[i++] = '\0';
		return (NULL);
	}
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		ft_clean_buffer(buffer);
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
		if (read(fd, buffer, BUFFER_SIZE) < 0)
			return (free (line), NULL);
	}
	return (line);
}
