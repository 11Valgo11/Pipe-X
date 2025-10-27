/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 06:20:50 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/04 21:59:22 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_pr
{
	pid_t	child1;
	pid_t	child2;
	int		fdpipe[2];
}	t_pr;

typedef struct s_quo
{
	int		quote;
	int		i;
	int		j;
}	t_quo;

typedef struct s_exec
{
	char	**path;
	char	*partjoin;
	char	*cmdjoined;
}	t_exec;

typedef struct s_split
{
	int	i;
	int	space;
	int	count;
	int	j;
	int	len;
}	t_split;

typedef struct s_splitv2
{
	int	i;
	int	j;
	int	start;
	int	wordnum;
	int	wordlen;
}	t_splitv2;

typedef struct s_splitv3
{
	int	i;
	int	j;
	int	start;
	int	wordnum;
	int	wordlen;
}	t_splitv3;

void	failfork(int *fd);
int		absopath(char *str);
void	ft_free(char **str);
char	**ft_split(char *str);
char	*trimbparse(char *str);
void	ft_puterror(char *str);
char	**ft_splitawk(char *str);
void	openfail(int fd, int fd2);
int		ft_strlen(char const *str);
void	ft_bzero(void *s, size_t n);
char	**splitspaceargs(char *str);
int		ft_strchr(char *str, char x);
void	dup2failed(int fd, int mode);
void	checknull(char *str, char *freed);
void	pathnexec(char **env, char **args);
int		openfile(char *str, int mode, int fd2);
char	**ft_splitchars(char const *s, char c);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strjoin(char *s1, char *s2);
void	execabso(char *path, char **args, char **env);
char	**checkfree(char **res, char *newstr, char *str, int mode);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif
