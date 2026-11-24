/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:08:41 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/24 18:18:17 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#ifndef	BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strchr(const char	*s, const char c);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
