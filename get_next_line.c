/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:08:38 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/25 15:07:32 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*new_stash;
	static char	*stash;
	char		*buffer;
	ssize_t		bytes_read;
	char		*line;
	char		*temp;
	size_t		i;
	size_t		j;

	if (BUFFER_SIZE <= 0)
    	return (NULL);
	if (fd < 0)
    	return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr(stash, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
		{
			if ((!stash) || (stash[0] == '\0'))
			{
				free(buffer);
				free(stash);
				stash = NULL;
				return (NULL);
			}
			i = ft_strlen(stash);
			line = ft_substr(stash, 0, i);
			free(buffer);
			free(stash);
			stash = NULL;
			return (line);
		}
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			temp = ft_strjoin(stash, buffer);
			if (temp == NULL)
			{
				free(stash);
				free(buffer);
				stash = NULL;
				return (NULL);
			}
			free(stash);
			stash = temp;
		}
	}
	free(buffer);
	i = ft_strlen(stash);
	j = ft_strlen(ft_strchr(stash, '\n'));
	line = ft_substr(stash, 0, i - j);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	new_stash = ft_substr(ft_strchr(stash, '\n'), 0, j);
	if(!new_stash)
	{
		free(stash);
		free(line);
		stash = NULL;
		line = NULL;
		return (NULL);
	}
	free(stash);
	stash = new_stash;
	return (line);
}


int	main(void)
{
	get_next_line(open("fd.txt", O_RDONLY));
}
