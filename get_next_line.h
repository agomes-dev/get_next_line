/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefe2 <andrefe2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:08:41 by andrefe2          #+#    #+#             */
/*   Updated: 2026/11/23 15:53:27 by andrefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

#ifndef	BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strchr(char	*s, char c);

#endif
