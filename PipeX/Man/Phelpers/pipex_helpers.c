/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 01:38:53 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/04 21:59:04 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strlen(char const *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (join == NULL)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (haystack == NULL && len == 0)
		return (NULL);
	if (haystack[0] == '\0')
		return (NULL);
	if (needle[0] == 0)
		return ((char *)haystack);
	j = 0;
	i = 0;
	while (haystack[i] && haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
		{
			j++;
			if (needle[j] == 0)
				return ((char *)haystack + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}

int	ft_strchr(char *str, char x)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == x)
			return (1);
		i++;
	}
	return (0);
}

int	absopath(char *str)
{
	if (ft_strnstr(str, "/", ft_strlen(str)))
		return (1);
	return (0);
}
