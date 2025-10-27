/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helpers_b2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:43:27 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/01 06:31:31 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

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

void	redlast(t_mult *m, char **argv, int argc)
{
	m->in = m->t;
	m->out = openfile(argv[argc - 1], 1, m->in);
}
