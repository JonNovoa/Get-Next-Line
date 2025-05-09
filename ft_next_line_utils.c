/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_line_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:35:21 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/08 19:28:25 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 || !s2)
		return (0);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;
	size_t			s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_extrac_line(char **remainder)
{
	char	*line;
	char	*temp;
	char	*nl_pos;
	size_t	len;

	if (!*remainder || !**remainder)
	{
		return (NULL);
	}
	nl_pos = ft_strchr(*remainder, '\n');
	if (nl_pos)
	{
		len = nl_pos - *remainder + 1;
		line = ft_substr(*remainder, 0, len);
		temp = ft_substr(*remainder,len, ft_strlen(*remainder) - len);
		free(*remainder);
		*remainder = temp;
	}
	else
	{
		line = ft_substr(*remainder, 0, ft_strlen(*remainder));
		free(*remainder);
		*remainder = NULL;
	}
	return (line);
}