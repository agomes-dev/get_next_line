/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 12:52:20 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/27 12:55:40 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#ifndef	BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#ifndef	MAX_FD
# define MAX_FD 1024
#endif


char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
const char	*ft_strchr(const char *s, const char c);
char		*ft_strjoin(const char *s1, const char *s2);
char 		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_free_all(char *buffer, char **stash);
char		*ft_extract_line(char **stash);
int			ft_read_to_stash(int fd, char **stash);
int			ft_append_buffer(char *buffer, char **stash);

#endif
