/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:27:54 by likong            #+#    #+#             */
/*   Updated: 2024/06/13 14:19:13 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*jump_to_newline(char *content)
{
	char	*new_content;
	char	*res;
	int		len;

	res = str_chr(content, '\n');
	if (!res)
	{
		new_content = NULL;
		return (ft_free(&content));
	}
	else
		len = (res - content) + 1;
	if (!content[len])
		return (ft_free(&content));
	new_content = substr(content, len, str_len(content, '\0') - len);
	ft_free(&content);
	if (!new_content)
		return (NULL);
	return (new_content);
}

// check and generate new string as end by '\n'
char	*check_line(char *content)
{
	char	*line;
	size_t	len;

	len = str_len(content, '\n');
	if (content[len] == '\n')
		len++;
	line = substr(content, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

// get the content from file, end by '\n' or to the end
char	*get_content(int fd, char *content)
{
	char	*content_buf;
	ssize_t	bytes;

	bytes = 1;
	content_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!content_buf)
		return (ft_free(&content));
	while ((content && bytes > 0 && !str_chr(content, '\n')) || !content)
	{
		bytes = read(fd, content_buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(content_buf);
			return (ft_free(&content));
		}
		if (bytes == 0)
			break ;
		content_buf[bytes] = '\0';
		content = str_join(content, content_buf);
	}
	free(content_buf);
	if (str_len(content, '\0') > 0)
		return (content);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	content = get_content(fd, content);
	if (!content)
		return (NULL);
	line = check_line(content);
	if (!line)
		return (ft_free(&content));
	content = jump_to_newline(content);
	return (line);
}
