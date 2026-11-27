/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:08:38 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/27 12:40:21 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	status = ft_read_to_stash(fd, &stash);
	if (status == -1)
		return (NULL);
	if (!stash || !stash[0])
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_extract_line(&stash);
	return (line);
}

int	ft_read_to_stash(int fd, char **stash)
{
	ssize_t	bytes_read;
	char	*buffer;

	if (ft_strchr(*stash, '\n'))
		return (1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free_all(NULL, stash));
	while (ft_strchr(*stash, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free_all(buffer, stash));
		if (bytes_read == 0)
		{
			free(buffer);
			return (0);
		}
		buffer[bytes_read] = '\0';
		if (ft_append_buffer(buffer, stash) == -1)
			return (ft_free_all(buffer, stash));
	}
	free(buffer);
	return (1);
}

int	ft_append_buffer(char *buffer, char **stash)
{
	char	*temp;

	temp = ft_strjoin(*stash, buffer);
	if (!temp)
		return (-1);
	free(*stash);
	*stash = temp;
	return (1);
}

char	*ft_extract_line(char **stash)
{
	const char	*newline;
	char		*line;
	char		*new_stash;
	size_t	j;

	newline = ft_strchr(*stash, '\n');
	j = 0;
	if (newline)
		j = ft_strlen(newline);
	line = ft_substr(*stash, 0, ft_strlen(*stash)- j);
	if (!line)
	{
		ft_free_all(NULL, stash);
		return (NULL);
	}
	new_stash = ft_substr(newline, 0, j);
	if (newline && !new_stash)
	{
		free(line);
		ft_free_all(NULL, stash);
		return (NULL);
	}
	free(*stash);
	*stash = new_stash;
	return (line);
}

int	ft_free_all(char *buffer, char **stash)
{
	free(buffer);
	free(*stash);
	*stash = NULL;
	return (-1);
}

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line : %s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
