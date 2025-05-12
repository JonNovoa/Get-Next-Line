/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nex_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:25:08 by jnovoa-a          #+#    #+#             */
/*   Updated: 2025/05/12 16:28:22 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

char	*ft_extract_line(char **stash)
{
	char	*line;
	char	*new_stash;
	char	*nl_pos;
	size_t	len;

	if (!*stash || !**stash)
	{
		return (NULL);
	}
	nl_pos = ft_strchr(*stash, '\n');
	if (nl_pos)
	{
		len = nl_pos - *stash + 1;
		line = ft_substr(*stash, 0, len);
		new_stash = ft_substr(*stash, len, ft_strlen(*stash) - len);
		free(*stash);
		*stash = new_stash;
	}
	else
	{
		line = *stash;
		*stash = NULL;
	}
	return (line);
}

char	*ft_get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
	}
	return (ft_extract_line(&stash));
}
