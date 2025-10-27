/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:16:55 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/01 09:33:54 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static	char	*linefirst(char *holder);
static	char	*scanbytes(int fd, char *holder, char *buffer);
static	char	*lastrest(char *holder);

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*buffer;
	char		*var;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE > INT_MAX)
		return (free(holder), holder = NULL, NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(holder), holder = NULL, NULL);
	holder = scanbytes(fd, holder, buffer);
	free (buffer);
	buffer = NULL;
	if (!holder)
		return (NULL);
	var = linefirst(holder);
	holder = lastrest(holder);
	return (var);
}

static char	*scanbytes(int fd, char *holder, char *buffer)
{
	ssize_t	rebytes;

	while (1)
	{
		if (ft_strchr(holder, '\n'))
			break ;
		rebytes = read(fd, buffer, BUFFER_SIZE);
		if (rebytes == -1)
		{
			free(holder);
			holder = NULL;
			return (NULL);
		}
		if (rebytes == 0)
			break ;
		buffer[rebytes] = '\0';
		holder = get_strjoin(holder, buffer);
	}
	return (holder);
}

static char	*linefirst(char *holder)
{
	char	*getline;
	int		i;

	i = 0;
	while (holder[i] && holder[i] != '\n')
		i++;
	if (holder[i] == '\n')
		i++;
	getline = malloc(i + 1);
	if (!getline)
		return (NULL);
	i = 0;
	while (holder[i] && holder[i] != '\n')
	{
		getline[i] = holder[i];
		i++;
	}
	if (holder[i] == '\n')
		getline[i++] = '\n';
	getline[i] = '\0';
	return (getline);
}

static char	*lastrest(char *holder)
{
	int		i;
	char	*rest;

	i = 0;
	if (!holder)
		return (NULL);
	while (holder[i] && holder[i] != '\n')
		i++;
	if (holder[i] == '\n')
		i++;
	rest = get_substr(holder, i, -1);
	if (!rest)
	{
		free(holder);
		return (NULL);
	}
	if (*rest == 0)
	{
		free(rest);
		rest = NULL;
		free(holder);
		return (NULL);
	}
	free (holder);
	return (rest);
}
