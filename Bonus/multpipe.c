/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multpipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:42:01 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/04 09:04:09 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	shutter(t_mult *m)
{
	close(m->in);
	close(m->out);
	m->i++;
	m->j++;
}

int	redin(t_mult *m, char **argv)
{
	if (pipe(m->fdp) == -1)
	{
		perror("pipe failed");
		return (-1);
	}
	m->t = m->fdp[0];
	m->out = m->fdp[1];
	m->in = open(argv[1], O_RDONLY, 0777);
	if (m->in == -1)
	{
		perror("open failed");
		return (-1);
	}
	return (0);
}

void	redbetween(t_mult *m)
{
	m->in = m->t;
	if (pipe(m->fdp) == -1)
	{
		perror("pipe failed");
		exit(1);
	}
	m->t = m->fdp[0];
	m->out = m->fdp[1];
}

void	procmd(t_mult *m, char **argv, char **arg, char **env)
{
	char	*str;

	dup2failed(m->in, 0);
	dup2failed(m->out, 1);
	close(m->in);
	close(m->out);
	close(m->t);
	str = ft_strtrim(argv[m->j], " ");
	argv[m->j] = trimbparse(str);
	arg = splitspaceargs(argv[m->j]);
	if (arg[0] == NULL)
	{
		ft_puterror("pipex: persmission denied:\n");
		exit(1);
	}
	pathnexec(env, arg);
}

void	multpipe(t_mult *m, int argc, char **argv, char **env)
{
	char	**arg;

	arg = NULL;
	m->fdp[0] = -1;
	m->fdp[1] = -1;
	while (m->i < m->npipes + 1 && m->j < argc - 1)
	{
		if (m->i == 0)
		{
			if (inred(m, argv) == -1)
				continue ;
		}
		else if (m->i == m->npipes)
			redlast(m, argv, argc);
		else
			redbetween(m);
		m->child = fork();
		childfail(m->child, *m);
		if (m->child == 0)
			procmd(m, argv, arg, env);
		shutter(m);
	}
	while (wait(NULL) != -1)
		;
	close(m->t);
}
