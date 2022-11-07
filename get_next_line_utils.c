/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irgonzal <irgonzal@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:29:53 by irgonzal          #+#    #+#             */
/*   Updated: 2022/11/07 13:39:48 by irgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "get_next_line.h"

int	ft_strlenint(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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
	}
	i = n;
	while (i > 0)
	{
		*(p1 + i - 1) = *(p2 + i - 1);
		i--;
	}
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	sdst;
	unsigned int	ssum;

	if (dst == 0 && dstsize == 0)
		return (ft_strlen(src));
	sdst = ft_strlen(dst);
	ssum = sdst;
	while (src[ssum - sdst] != '\0' && (ssum + 1) < dstsize)
	{
		dst[ssum] = src[ssum - sdst];
		ssum++;
	}
	if (sdst < dstsize)
		dst[ssum] = '\0';
	while (src[ssum - sdst] != '\0')
		ssum++;
	if (sdst > dstsize)
		return (ssum - sdst + dstsize);
	return (ssum);
}
