/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:42:57 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/04 21:46:48 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	*parseput(char *lim, int argc, char **argv)
{
	if (argc != 6)
	{
		ft_puterror("Bad format: ./pipex here_doc LIMITER cmd cmd1 file\n");
		exit(1);
	}
	lim = malloc(ft_strlen(argv[2]) + 1);
	if (!lim)
		exit(1);
	return (lim);
}

char	*gitline(char *lim)
{
	char	*str;
	char	*buffer;
	int		f;
	char	*lim2;

	str = NULL;
	buffer = NULL;
	buffer = gename(buffer, lim);
	f = bufferfile(buffer, lim);
	ft_puterror("pipex heredoc> ");
	str = get_next_line(STDIN_FILENO);
	lim2 = ft_strjoin(lim, "\n", buffer);
	while (str != NULL && (limcmp(str, lim2) != 0))
	{
		ft_puterror("pipex heredoc> ");
		if (limcmp(str, lim) != 0)
			ft_putstr(str, f);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	close(f);
	free(lim2);
	free(str);
	return (buffer);
}

void	waitclose(t_pr proc)
{
	close(proc.fdpipe[0]);
	close(proc.fdpipe[1]);
	waitpid(proc.child1, NULL, 0);
	waitpid(proc.child2, NULL, 0);
}

void	filedeletion(char *str)
{
	if (unlink(str) == -1)
	{
		perror("unlink failed");
		exit(1);
	}
}

void	here_doc(int argc, char **argv, char **env)
{
	t_pr	proc;
	char	*buffer;
	char	*lim;

	lim = NULL;
	if (pipe(proc.fdpipe) == -1)
	{
		perror("pipe failed");
		exit(1);
	}
	lim = parseput(lim, argc, argv);
	ft_strcpy(lim, argv[2]);
	buffer = gitline(lim);
	proc.child1 = fork();
	ft_childfail(proc.child1, proc.fdpipe, lim, buffer);
	if (proc.child1 == 0)
		ft_kid1(argv, env, proc.fdpipe, buffer);
	proc.child2 = fork();
	ft_childfail(proc.child2, proc.fdpipe, lim, buffer);
	if (proc.child2 == 0)
		ft_kid2(argv, argc, env, proc.fdpipe);
	waitclose(proc);
	free(lim);
	free(buffer);
}
