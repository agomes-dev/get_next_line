/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 12:52:46 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/27 13:56:38 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;
	int			status;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	status = ft_read_to_stash(fd, &stash[fd]);
	if (status == -1)
		return (NULL);
	if (!stash[fd] || !stash[fd][0])
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = ft_extract_line(&stash[fd]);
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
/*
int	main(int argc, char **argv)
{
	char	*line;
	char	*line1;
	char	*line2;
	int		fd;
	int		fd1;
	int		fd2;


	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	if (argc == 4)
	{
		fd = open(argv[1], O_RDONLY);
		fd1 = open(argv[2], O_RDONLY);
		fd2 = open(argv[3], O_RDONLY);
	}
	else
	{
		fd = 0;
		fd1 = 0;
		fd2 = 0;
	}
	printf("fd %d\n", fd);
	printf("fd %d\n", fd1);
	printf("fd %d\n", fd2);
	line = get_next_line(fd);
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	while (line != NULL || line1 != NULL || line2 != NULL)
	{
		printf("line first file : %s\n", line);
		printf("line second file : %s\n", line1);
		printf("line third file : %s\n", line2);
		free(line);
		free(line1);
		free(line2);
		line = get_next_line(fd);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
	}
	close(fd);
	close(fd1);
	close(fd2);
}
*/
