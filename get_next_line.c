/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:50:44 by irgonzal          #+#    #+#             */
/*   Updated: 2022/11/07 15:59:27 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
int	end_in_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (str[i] == '\n')
			return (i);
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char			*aux;//
	char			*line;
	static char		*buf = "\0";
	size_t			size;

	buf = malloc(BUFFER_SIZE * sizeof(char));
	printf("gnl, %d", BUFFER_SIZE);
	size = end_in_str(buf);
	while (size == ft_strlen(buf) && ft_strlen(buf) == BUFFER_SIZE)
	{
		printf("bucle\n");
		line = ft_strjoin(line, buf);
		read(fd, buf, BUFFER_SIZE);
		size = end_in_str(buf);
	}
	aux = ft_substr(buf, 0, size);
	line = ft_strjoin(line, aux);
	ft_memmove(line, aux, ft_strlen(aux));
	buf = ft_substr(buf, size, ft_strlen(buf) - size);
	free(aux);
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
