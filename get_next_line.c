/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:48:33 by irgonzal          #+#    #+#             */
/*   Updated: 2023/01/23 17:48:36 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "get_next_line.h"

static size_t	contains_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i + 1);
	return (0);
}

char	*prepare_line(char *aux, size_t pos_nl)
{
	char	*line;

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
	if (bytes == 0)
		return ("\0");//demasiado drástico?
	buffer[BUFFER_SIZE] = '\0';
	//printf("buffer %s|\n", buffer);
	if (rem[0] != '\0')
	{
		aux = ft_strdup(rem);
		free(rem);
	}
	else
		aux = "\0";
	rem = ft_strjoin(aux, buffer);
	if (aux[0] != '\0')
		free(aux);
	free(buffer);
	return (rem);
}

char	*get_next_line(int fd)
{
	static char	*remains = "\0";
	char		*aux;
	size_t		pos_nl;

	if (remains[0] == '\0')
		remains = load_buffer(remains, fd);
	if (!remains || remains[0] == '\0')
		return (NULL);
	while (contains_line(remains) == 0 && ft_strlen(remains) != 0)
	{
		remains = load_buffer(remains, fd);
		if (!remains || remains[0] == '\0')
			return (NULL);
	}
	aux = ft_strdup(remains);
	if (!aux)
		return (NULL);
	pos_nl = contains_line(aux);
	free(remains);
	remains = ft_substr(aux, pos_nl, ft_strlen(aux) - pos_nl);
	return (prepare_line(aux, pos_nl));
}
