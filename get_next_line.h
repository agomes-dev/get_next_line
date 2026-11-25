/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:08:41 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/25 15:06:31 by andrefe2         ###   ########.fr       */
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

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
const char	*ft_strchr(const char *s, const char c);
char		*ft_strjoin(const char *s1, const char *s2);
char 		*ft_substr(char const *s, unsigned int start, size_t len);


#endif
