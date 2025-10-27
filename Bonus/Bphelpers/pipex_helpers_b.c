/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helpers_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:43:23 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/04 22:17:22 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	*gen2lay(char *str)
{
	char	*newstr;
	char	*gen2;

	gen2 = malloc(ft_strlen("gen2") + 1);
	if (!gen2)
		return (NULL);
	gen2 = "gen2";
	newstr = ft_strjoin(gen2, str, NULL);
	return (newstr);
}

void	childfail(pid_t child, t_mult m)
{
	if (child == -1)
	{
		perror("fork failed");
		close(m.in);
		close(m.out);
		close(m.t);
		exit(1);
	}
}

char	*ft_strjoin(char *s1, char *s2, char *buffer)
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
		free(buffer);
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
	while (haystack[i] && i < len)
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

int	inred(t_mult *m, char **argv)
{
	if (redin(m, argv) == -1)
	{
		m->j++;
		m->i = 1;
		if (m->fdp[1] != -1)
			close(m->fdp[1]);
		return (-1);
	}
	return (0);
}
