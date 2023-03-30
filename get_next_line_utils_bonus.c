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
	unsigned int	len;
	char			*str;

	l1 = 0;
	if (s1)
		l1 = ft_strlen(s1);
	len = l1;
	if (s2)
		len += ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, l1);
	ft_memmove(str + l1, s2, len - l1);
	str[len] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*p1;
	const char	*p2;

	if (dst == 0 && src == 0)
		return (dst);
	p1 = dst;
	p2 = src;
	if (p1 < p2 || (long unsigned int)(p1 - p2) > n)
	{
		i = 0;
		while (i < n)
		{
			p1[i] = p2[i];
			i++;
		}
		return (dst);
	}
	i = n;
	while (i > 0)
	{
		*(p1 + i - 1) = *(p2 + i - 1);
		i--;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
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
