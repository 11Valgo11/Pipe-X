/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helpers_b3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:43:35 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/02/23 20:43:59 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	*ft_strdup(char *s1)
{
	size_t		i;
	char		*dup;

	if (!s1)
		return (NULL);
	dup = malloc(ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*new;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		new[i] = s[i + start];
		i++;
	}
	new[len] = '\0';
	return (new);
}

static int	checkset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int	s;
	int	e;

	if (!s1 || !set)
		return (NULL);
	s = 0;
	e = ft_strlen(s1) - 1;
	while (s1[s] && checkset(s1[s], set))
		s++;
	while (s1[e] && checkset(s1[e], set))
		e--;
	if (e == -1)
		return (ft_substr(s1, s, 0));
	return (ft_substr(s1, s, (e - s + 1)));
}
