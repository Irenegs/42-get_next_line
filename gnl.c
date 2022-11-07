/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:50:44 by irgonzal          #+#    #+#             */
/*   Updated: 2022/10/28 17:44:41 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "get_next_line.h"

char	*buf_copy(char *buf, char *aux, char c)
{
	int	l_aux;

	free(buf);
	l_aux = ft_strlen(aux);
	buf = malloc(sizeof(char) * (l_aux + 2));
	if (!buf)
		return (NULL);
	ft_memmove(buf, aux, l_aux);
	ft_strlcat(buf, &c, l_aux + 2);
	free(aux);
	aux = malloc(sizeof(char) * (l_aux + 2));
	ft_memmove(aux, buf, l_aux + 1);
	aux[l_aux + 1] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*aux;
	char	c;

	read(fd, &c, 1);
	if (c == '\0')
		return (NULL);
	aux = malloc(sizeof(char));
	buf = malloc(sizeof(char));
	if (!buf || !aux)
		return (NULL);
	*aux = '\0';
	while (c != '\n' && c != '\0')
	{
		if (buf_copy(buf, aux, c) == NULL)
			return (NULL);
		read(fd, &c, 1);
	}
	if (buf_copy(buf, aux, c) == NULL)
		return (NULL);
	free(aux);
	return (buf);
}
