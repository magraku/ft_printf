/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:48:46 by gerramir          #+#    #+#             */
/*   Updated: 2026/05/15 20:35:31 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*afterchr(char const *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*read_buf(int fd);
char	*put_line(char **sta, char **keep_tmp);
char	*put_line2(char **sta);
#endif