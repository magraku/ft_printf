/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:14:27 by gerramir          #+#    #+#             */
/*   Updated: 2026/05/15 21:40:37 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	slen;

	j = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (start >= slen)
	{
		new = malloc(1);
		if (!new)
			return (NULL);
		return (new[0] = '\0', new);
	}
	if (len > slen - start)
		len = slen - start;
	new = malloc((sizeof(char)) * (len + 1));
	if (!new)
		return (NULL);
	i = start;
	while (j < len && s[i])
		new[j++] = s[i++];
	return (new[j] = '\0', new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	new = malloc(len1 + len2 + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 != NULL && s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2 != NULL && s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}

char	*afterchr(char const *str, char c)
{
	char	*start;
	char	*new;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	start = ft_strchr(str, c);
	if (str[i] == '\n' && str[i + 1] == '\0')
		return (NULL);
	if (start)
	{
		while (start[i + 1])
			i++;
		new = ft_substr(str, start - str + 1, i);
		return (new);
	}
	else
		return (NULL);
}
