/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:08:38 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/23 15:56:46 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	ssize_t		bytes_read;
	char		*line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
}
