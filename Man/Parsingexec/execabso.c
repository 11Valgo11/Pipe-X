/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execabso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 01:38:17 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/02/28 03:11:17 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	execabso(char *path, char **args, char **env)
{
	path = args[0];
	if (execve(path, args, env) == -1)
	{
		perror("execve failed");
		exit(1);
	}
}

void	openfail(int fd, int fd2)
{
	if (fd == -1)
	{
		close(fd2);
		perror("open failed");
		exit(1);
	}
}

void	dup2failed(int fd, int mode)
{
	if (mode == 1)
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			close(fd);
			perror("dup2 failed");
			exit(1);
		}
	}
	else if (mode == 0)
	{
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			close(fd);
			perror("dup2 failed");
			exit(1);
		}
	}
}
