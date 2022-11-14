/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:50:44 by irgonzal          #+#    #+#             */
/*   Updated: 2022/11/10 12:30:32 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "get_next_line.h"
#include <stdio.h>

size_t	end_in_str(char *str)
{
	size_t	i;

	i = 0;
	printf("end\n");
	while (str[i] != '\0' && i < BUFFER_SIZE)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	printf("endend\n");
	return (i);
}

char	*get_next_line(int fd)
{
	char			*aux;
	char			*line;
	static char		*buf = "\0";
	size_t			size;

	printf("hola\n");
	if (ft_strlen(buf) == 0)
	{
		printf("buf malloc\n");
		buf = malloc(BUFFER_SIZE * sizeof(char));
		if (!buf)
			return (NULL);
		printf("buf malloc\n");
		read(fd, buf, BUFFER_SIZE);
		printf("buf read\n");
	}
	printf("buf reserved\n");
	size = end_in_str(buf);
	if (size == 0 && ft_strlen(buf) == 0)
	{
		printf("if2\n");
		free(buf);
		return (NULL);
	}
	line = "\0";
	while (size == ft_strlen(buf) && ft_strlen(buf) == BUFFER_SIZE)
	{
		printf("bf append\n");
		line = ft_strappendn(line, buf, BUFFER_SIZE);
		printf("af append\n");
		read(fd, buf, BUFFER_SIZE);
		size = end_in_str(buf);
	}
	line = ft_strappendn(line, buf, size);
	buf = ft_substr(buf, size + 1, ft_strlen(buf) - size);
	return (line);
}
/*	



	buf = '\0';
	size = end_in_str(rest);
	if (size > -1)
	{
		line = ft_substr(rest, 0, size);
		rest = ft_substr(rest, size, ft_strlen(rest) - size);
	}
	else
	{
		aux = ft_substr(rest, 0, ft_strlen(rest));
		buf = malloc(sizeof(char) * BUFFER_SIZE);
		if (!buf)
			return (NULL);
		read(fd, buf, BUFFER_SIZE);
		size = end_in_str(buf);
		if (size > -1)
		{
			free(line);
			line = malloc((ft_strlenint(aux) + BUFFER_SIZE) * sizeof(char));
			ft_strlcat(line, buf, ft_strlenint(aux));
			free(aux);
			aux = ft_substr(line, 0, ft_strlen(line));
		}
		else
		{
			line = malloc((ft_strlen(rest) + ft_strlen(aux) + size + 1) * sizeof(char));
			ft_memmove(line, rest, ft_strlen(rest));
			ft_strlcat(line, aux, ft_strlen(rest) + ft_strlen(aux));
			ft_strlcat(line, buf, ft_strlen(rest) + ft_strlen(aux) + size + 1);
			ft_memmove(rest, buf, 
		}
	}
	return (line);


	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	to_copy(buf, aux,  
}*/
