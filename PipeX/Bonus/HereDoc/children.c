/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:42:08 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/04 21:53:55 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_kid1(char **argv, char **env, int *fdpipe, char *buffer)
{
	char	**arg2;
	int		fd;
	char	*str;

	arg2 = NULL;
	str = NULL;
	close(fdpipe[0]);
	fd = open(buffer, O_RDONLY, 0777);
	openfail(fd, fdpipe[1]);
	dup2failed(fd, 0);
	close(fd);
	dup2failed(fdpipe[1], 1);
	close(fdpipe[1]);
	filedeletion(buffer);
	str = ft_strtrim(argv[3], " ");
	argv[3] = trimbparse(str);
	arg2 = splitspaceargs(argv[3]);
	if (arg2[0] == NULL)
	{
		ft_puterror("pipex: persmission denied:\n");
		exit(1);
	}
	pathnexec(env, arg2);
}

void	ft_kid2(char **argv, int argc, char **env, int *fdpipe)
{
	char	**arg2;
	int		fd;
	char	*str;

	arg2 = NULL;
	str = NULL;
	close(fdpipe[1]);
	fd = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0777);
	openfail(fd, fdpipe[0]);
	dup2failed(fdpipe[0], 0);
	close(fdpipe[0]);
	dup2failed(fd, 1);
	close(fd);
	str = ft_strtrim(argv[4], " ");
	argv[4] = trimbparse(str);
	arg2 = splitspaceargs(argv[4]);
	if (arg2[0] == NULL)
	{
		ft_puterror("pipex: persmission denied:\n");
		exit(1);
	}
	pathnexec(env, arg2);
}

void	ft_strcpy(char *lim, char *str)
{
	int	i;

	if (!lim)
		exit(1);
	i = 0;
	while (str[i])
	{
		lim[i] = str[i];
		i++;
	}
	lim[i] = '\0';
}

int	limcmp(char *str, char *lim)
{
	int	i;

	if (!str)
		exit(1);
	i = 0;
	while ((str[i] || lim[i]))
	{
		if (str[i] != lim[i])
			return (str[i] - lim[i]);
		i++;
	}
	return (0);
}

int	bufferfile(char *str, char *lim)
{
	int	fd;

	fd = 0;
	if (access(str, F_OK) == -1)
	{
		fd = open(str, O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fd == -1)
		{
			freeier(str, lim);
			exit(1);
		}
	}
	else if (access(str, F_OK))
	{
		str = gen2lay(str);
		fd = open(str, O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fd == -1)
		{
			freeier(str, lim);
			exit(1);
		}
		free(str);
	}
	return (fd);
}
