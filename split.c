/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:03:41 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/27 12:23:00 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*alloc;
	unsigned char	*iter;
	size_t			full_s;

	if (!nmemb || !size)
		return (NULL);
	full_s = nmemb * size;
	if (nmemb != full_s / size)
		return (NULL);
	alloc = malloc(full_s);
	if (!alloc)
		return (NULL);
	iter = alloc;
	while (full_s--)
		*iter++ = 0;
	return ((void *)alloc);
}

static char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*sub;
	char		*sub_ptr;
	size_t		str_len;

	if (!s)
		return (NULL);
	str_len = 0;
	while (s[str_len])
		str_len++;
	if (start >= str_len)
		return (ft_calloc(1, sizeof(char)));
	if (len > str_len - start)
		len = str_len - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	sub_ptr = sub;
	s += start;
	while (len--)
		*sub_ptr++ = *s++;
	return (sub);
}

static size_t	ft_sub_count(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	**ft_rec_split(char *s, char c, char **str)
{
	char	*substr;

	while (*s && *s == c)
		s++;
	if (!*s)
		return (NULL);
	substr = s;
	while (*s && *s != c)
		s++;
	*str = ft_substr(substr, 0, s - substr);
	if (!*str)
		return (NULL);
	return (ft_rec_split(s, c, str + 1));
}

char	**ft_split(char *s, char c)
{
	char	**str;
	char	**clean;

	if (!s)
		return (NULL);
	str = ft_calloc(ft_sub_count(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	clean = str;
	if (!ft_rec_split(s, c, str))
	{
		while (*clean)
			free(*clean++);
		free(str);
		return (NULL);
	}
	return (str);
}
