/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:17:44 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/04 21:54:13 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	failfork(int *fd)
{
	perror("fork failed\n");
	close(fd[0]);
	close(fd[1]);
	exit(1);
}

void	ft_childfail(pid_t child, int *fd, char *lim, char *buffer)
{
	if (child == -1)
	{
		failfork(fd);
		free(lim);
		free(buffer);
	}
}

void	freeier(char *str, char *lim)
{
	free(str);
	free(lim);
	perror("open failed");
}
