/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:11:49 by gerramir          #+#    #+#             */
/*   Updated: 2026/05/15 21:39:25 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_sizenl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (i + 1);
}

char	*read_buf(int fd)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(buf);
		return (NULL);
	}
	buf[bytes] = '\0';
	return (buf);
}

char	*put_line(char **sta, char **keep_tmp)
{
	char	*line;

	line = ft_substr(*sta, 0, ft_sizenl(*sta));
	free(*sta);
	*sta = *keep_tmp;
	return (line);
}

char	*put_line2(char **sta)
{
	char	*line;

	line = ft_substr(*sta, 0, ft_strlen(*sta));
	free(*sta);
	*sta = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*sta;
	char		*buf;
	char		*keep_tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	keep_tmp = afterchr(sta, '\n');
	if (keep_tmp)
		return (put_line(&sta, &keep_tmp));
	buf = read_buf(fd);
	while (buf)
	{
		keep_tmp = sta;
		sta = ft_strjoin(keep_tmp, buf);
		free(keep_tmp);
		free(buf);
		keep_tmp = afterchr(sta, '\n');
		if (keep_tmp)
			return (put_line(&sta, &keep_tmp));
		buf = read_buf(fd);
	}
	free(buf);
	if (sta && sta[0])
		return (put_line2(&sta));
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("./file.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
