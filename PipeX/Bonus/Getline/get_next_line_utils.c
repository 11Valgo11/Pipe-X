/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:42:46 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/02/22 03:41:36 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_strdup(char *s1)
{
	int		i;
	char	*dup;

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

char	*get_strjoin(char *holder, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!holder)
		return (get_strdup(buffer));
	if (!buffer)
		return (get_strdup(holder));
	if (!buffer && !holder)
		return (NULL);
	i = -1;
	j = -1;
	join = malloc(ft_strlen(holder) + ft_strlen(buffer) + 1);
	if (join == NULL)
		return (free(holder), NULL);
	while (holder[++i])
		join[i] = holder[i];
	while (buffer[++j])
		join[i++] = buffer[j];
	join[ft_strlen(holder) + ft_strlen(buffer)] = '\0';
	free(holder);
	return (join);
}

int	ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}

char	*get_substr(char *s, int start, int len)
{
	int		i;
	char	*new;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (get_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[i + start];
		i++;
	}
	new[len] = '\0';
	return (new);
}
