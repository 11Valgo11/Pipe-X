/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 01:39:14 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/04 08:39:17 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_format(int argc)
{
	if (argc != 5)
	{
		ft_puterror("bad arguments: ./pipex file1 cmd1 cmd2 file2\n");
		exit(1);
	}
}

void	ft_kid1(t_pr proc, char **argv, char **env)
{
	int		infile;
	char	**arg1;
	char	*str;

	close(proc.fdpipe[0]);
	infile = openfile(argv[1], 0, proc.fdpipe[1]);
	dup2failed(infile, 0);
	close(infile);
	dup2failed(proc.fdpipe[1], 1);
	close(proc.fdpipe[1]);
	str = ft_strtrim(argv[2], " ");
	argv[2] = trimbparse(str);
	arg1 = splitspaceargs(argv[2]);
	if (arg1[0] == NULL)
	{
		ft_puterror("pipex: persmission denied:\n");
		exit(1);
	}
	pathnexec(env, arg1);
}

void	ft_kid2(t_pr proc, char **argv, char **env)
{
	int		outfile;
	char	**arg2;
	char	*str;

	close(proc.fdpipe[1]);
	outfile = openfile(argv[4], 1, proc.fdpipe[0]);
	dup2failed(outfile, 1);
	close(outfile);
	dup2failed(proc.fdpipe[0], 0);
	close(proc.fdpipe[0]);
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

void	closenwait(t_pr proc)
{
	close(proc.fdpipe[0]);
	close(proc.fdpipe[1]);
	waitpid(proc.child1, NULL, 0);
	waitpid(proc.child2, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	t_pr	proc;

	check_format(argc);
	if (pipe(proc.fdpipe) == -1)
	{
		perror("pipe failed");
		exit(1);
	}
	proc.child1 = fork();
	if (proc.child1 == -1)
		failfork(proc.fdpipe);
	else if (proc.child1 == 0)
		ft_kid1(proc, argv, env);
	proc.child2 = fork();
	if (proc.child2 == -1)
		failfork(proc.fdpipe);
	else if (proc.child2 == 0)
		ft_kid2(proc, argv, env);
	closenwait(proc);
}
