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

#	include "get_next_line.h"

static size_t	find_br(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}
/*
char	*add_string(char *s1, char *s2)
{
	char	*result;
	size_t	s;

	if (!s1 || !s2)
		return (NULL); 
	s = ft_strlen(s1) + ft_strlen(s2);
	result = malloc((s + 1) * sizeof(char));
	ft_memmove(result, s1, ft_strlen(s1));
	ft_memmove(result + ft_strlen(s1), s2, ft_strlen(s2));
	result[s] = '\0';
	if (s1[0] != '\0')
		free(s1);
	return (result);
}
*/
char	*read_line(int fd)
{
	int		bytes;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (bytes == 0)
	{
		free(buffer);
		return ("\0");
	}
	buffer[bytes] = '\0';
	return (buffer);
}

void	prepare_line(char *array[], char *rem)
{
	if (!rem || rem[0] == '\0')
	{
		array[0] = NULL;
		array[1] = NULL;
	}
	else if (rem[find_br(rem)] != '\n')
	{
		array[0] = ft_substr(rem, 0, ft_strlen(rem)); 
		array[1] = NULL;
	}
	else
	{
		array[0] = ft_substr(rem, 0, find_br(rem) + 1); 
		array[1] = ft_substr(rem, find_br(rem) + 1, ft_strlen(rem) - find_br(rem));
	}
}

char	*get_next_line(int fd)
{
	static char	*rem = NULL;
	char		*line;
	char		*buffer;
	char		*array[2];
	
	if (fd < 0)
		return (NULL);
	if (!rem || rem[find_br(rem)] != '\n')
	{
		buffer = read_line(fd);
		while (buffer && buffer[0] != '\0' && find_br(buffer) == ft_strlen(buffer))
		{
			line = ft_strjoin(rem, buffer);
			free(rem);
			rem = line;
			free(buffer);
			buffer = read_line(fd);
		}
		if (!buffer)
		{
			free(rem);
			return (NULL);
		}
	}
	if (find_br(buffer) != ft_strlen(buffer))
	{
		line = ft_strjoin(rem, buffer);
		free(rem);
		rem = line;
		free(buffer);
	}
	prepare_line(array, rem);
	free(rem);
	rem = array[1];
	return (array[0]);
}


/*
char	*prepare_line(char *aux, size_t pos_nl)
{
	char	*line;

	line = NULL;
	if (ft_strlen(aux) != 0)
		line = ft_substr(aux, 0, pos_nl + 1);
	free(aux);
	return (line);
}

static char	*load_buffer(char *rem, int fd)
{
	char	*buffer;
	char	*aux;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	aux = ft_strdup(rem);
	if (rem[0] != '\0')
		free(rem);
	rem = ft_strjoin(aux, buffer);
	free(aux);
	free(buffer);
	return (rem);
}

char	*get_next_line(int fd)
{
	static char	*rem = "\0";
	char		*aux;
	size_t		pos_nl;

	if (fd < 1)
		return (NULL);
	if (rem[0] == '\0')
		rem = load_buffer(rem, fd);
	if (!rem || rem[0] == '\0')
		return (NULL);
	pos_nl = 0;
	while (ft_strlen(rem) == find_br(rem) && pos_nl != find_br(rem))
	{
		pos_nl = find_br(rem);
		rem = load_buffer(rem, fd);
		if (!rem || rem[0] == '\0')
			return (NULL);
	}
	aux = ft_strdup(rem);
	free(rem);
	if (!aux)
		return (NULL);
	pos_nl = find_br(aux);
	rem = ft_substr(aux, pos_nl + 1, ft_strlen(aux) - pos_nl);
	if (rem[0] == '\0')
	{
		free(rem);
		rem = "\0";
	}
	return (prepare_line(aux, pos_nl));
}
*/