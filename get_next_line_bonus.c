/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:48:33 by irgonzal          #+#    #+#             */
/*   Updated: 2023/01/24 13:38:22 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "get_next_line_bonus.h"

static size_t	find_br(char *s, int index)
{
	int	i;

	i = index;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

ssize_t	read_line(char **rem, int fd)
{
	ssize_t	bytes;
	char	*buffer;
	char	*line;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes >= 0)
	{
		buffer[bytes] = '\0';
		line = ft_strjoin(*rem, buffer);
		free(*rem);
		*rem = line;
	}
	free(buffer);
	return (bytes);
}

void	prepare_line(char *array[], char *rem)
{
	size_t	br;

	br = find_br(rem, 0);
	if (!rem || rem[0] == '\0')
	{
		array[0] = NULL;
		array[1] = NULL;
	}
	else if (rem[br] != '\n')
	{
		array[0] = ft_substr(rem, 0, ft_strlen(rem));
		array[1] = NULL;
	}
	else
	{
		array[0] = ft_substr(rem, 0, br + 1);
		array[1] = ft_substr(rem, br + 1, ft_strlen(rem) - br);
	}
}

char	*get_next_line(int fd)
{
	static char	*cache[FOPEN_MAX];
	char		*array[2];
	ssize_t		bytes;
	char		*rem;
	int			index;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	rem = cache[fd];
	index = ft_strlen(rem);
	if (!rem || rem[find_br(rem, 0)] != '\n')
	{
		bytes = read_line(&rem, fd);
		while (bytes > 0 && rem[find_br(rem, index)] != '\n')
		{
			index += bytes;
			bytes = read_line(&rem, fd);
		}
		if (bytes < 0)
		{
			free(rem);
			return (cache[fd] = NULL);
		}
	}
	prepare_line(array, rem);
	free(rem);
	cache[fd] = array[1];
	return (array[0]);
}
