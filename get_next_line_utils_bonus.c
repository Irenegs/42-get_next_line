/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:56:57 by irgonzal          #+#    #+#             */
/*   Updated: 2023/01/23 17:57:03 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	l1;
	unsigned int	l2;
	char			*str;
	size_t			i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = malloc((l1 + l2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (++i < l1 + 1)
		str[i -1] = s1[i - 1];
	i = 0;
	while (++i < l2 + 1)
		str[l1 + i - 1] = s2[i - 1];
	str[l1 + l2] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	size_t			lens;

	lens = ft_strlen(s);
	if (!s)
		return (NULL);
	if (len > lens - start)
		len = lens - start;
	if (start >= lens)
		len = 0;
	p = malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
