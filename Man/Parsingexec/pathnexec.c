/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathnexec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 05:29:22 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/04 22:13:44 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	escapenv(char **env, t_exec *exec, int *i)
{
	while (env[*i])
	{
		if (ft_strnstr(env[*i], "PATH=", 5))
			break ;
		(*i)++;
	}
	exec->path = ft_splitchars(env[*i], ':');
}

char	*findpath(char **args, char **env, t_exec *exec)
{
	int	i;

	if (args[0] == NULL || env == NULL)
		return (NULL);
	i = 0;
	escapenv(env, exec, &i);
	if (exec->path)
	{
		i = 0;
		while (exec->path[i])
		{
			exec->partjoin = ft_strjoin(exec->path[i], "/");
			exec->cmdjoined = ft_strjoin(exec->partjoin, args[0]);
			free(exec->partjoin);
			if (access(exec->cmdjoined, X_OK) == 0)
				return (exec->cmdjoined);
			free(exec->cmdjoined);
			i++;
		}	
	}
	return (NULL);
}

void	pathnexec(char **env, char **args)
{
	t_exec	exec;
	char	*path;

	path = NULL;
	if (absopath(args[0]) == 0)
	{	
		path = findpath(args, env, &exec);
		if (path == NULL)
		{
			ft_puterror("command not found: ");
			if (args[0] != NULL)
				ft_puterror(args[0]);
			write(2, "\n", 1);
			exit(1);
		}
		else if (execve(path, args, env) == -1)
		{
			perror("execve failed");
			exit(1);
		}
	}
	else
		execabso(path, args, env);
}
