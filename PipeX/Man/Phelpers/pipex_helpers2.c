/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 01:39:02 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/01 06:12:31 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	openfile(char *str, int mode, int fd2)
{
	int	fd;

	fd = 0;
	if (mode == 0)
	{
		fd = open(str, O_RDONLY, 0777);
		openfail(fd, fd2);
		return (fd);
	}
	else if (mode == 1)
	{
		fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		openfail(fd, fd2);
		return (fd);
	}
	return (fd);
}

char	**checkfree(char **res, char *newstr, char *str, int mode)
{
	if (mode == 0)
	{
		res = ft_splitawk(str);
		checknull(*res, str);
	}
	if (mode == 1)
	{
		res = ft_splitchars(str, ' ');
		checknull(*res, str);
	}
	if (mode == 2)
	{
		res = ft_split(newstr);
		checknull(*res, str);
	}
	return (res);
}

void	checknull(char *str, char *freed)
{
	if (str == NULL)
	{
		free(freed);
		freed = NULL;
	}
}
