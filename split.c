/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:03:41 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/26 20:39:45 by paude-so         ###   ########.fr       */
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

static size_t	nb_count(char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s && *s != ' ')
		{
			count++;
			while (*s && *s != ' ')
				s++;
		}
	}
	return (count);
}

static char	**fill_matrix(char *s, char **str)
{
	char	*substr;

	while (*s && *s == ' ')
		s++;
	if (!*s || (*s + 1) == ' ')
		return (NULL);
	substr = s;
	while (*s && *s != ' ')
		s++;
	*str = ft_substr(substr, 0, s - substr);
	if (!*str)
	{
		while (*--str)
			free(*str);
		free(str);
		return (NULL);
	}
	return (fill_matrix(s, str + 1));
}

char	**split(char *s)
{
	char	**str;
	char	**clean;

	if (!s)
		return (NULL);
	str = ft_calloc(nb_count(s) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	clean = str;
	if (!fill_matrix(s, str))
	{
		while (*clean)
			free(*clean++);
		free(str);
		return (NULL);
	}
	return (str);
}
