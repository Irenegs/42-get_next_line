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

static size_t	contains_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*prepare_line(char *aux, size_t pos_nl)
{
	char	*line;

	line = NULL;
	if (ft_strlen(aux) != 0)
		line = ft_substr(aux, 0, pos_nl);
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
	printf("%lu %lu", pos_nl, contains_line(rem));
	while (ft_strlen(rem) == contains_line(rem) && pos_nl != contains_line(rem))
	{
		pos_nl = contains_line(rem);
		rem = load_buffer(rem, fd);
		if (!rem || rem[0] == '\0')
			return (NULL);
		printf("%lu %lu", pos_nl, contains_line(rem));
	}
	aux = ft_strdup(rem);
	if (!aux)
		return (NULL);
	pos_nl = contains_line(aux);
	free(rem);
	rem = ft_substr(aux, pos_nl, ft_strlen(aux) - pos_nl);
	return (prepare_line(aux, pos_nl));
}
