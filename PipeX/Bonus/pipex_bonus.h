/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:05:41 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/04 21:52:38 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_pr
{
	int		fdpipe[2];
	pid_t	child1;
	pid_t	child2;
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

typedef struct s_mult
{
	int		x;
	int		i;
	int		j;
	int		t;
	int		in;
	int		out;
	int		fdp[2];
	pid_t	child;
	int		npipes;
}	t_mult;

void	failfork(int *fd);
void	ft_free(char **str);
int		absopath(char *str);
char	*gen2lay(char *str);
char	*gitline(char *lim);
void	filedeletion(char *str);
void	openfail(int fd, int fd2);
void	ft_bzero(void *s, size_t n);
int		limcmp(char *str, char *lim);
int		inred(t_mult *m, char **argv);
int		redin(t_mult *m, char **argv);
void	ft_strcpy(char *lim, char *str);
int		bufferfile(char *str, char *lim);
int		ft_strcmp(char *str1, char *str2);
void	checknull(char *str, char *freed);
void	pathnexec(char **env, char **args);
int		openfile(char *str, int mode, int fd2);
char	*get_substr(char *s, int start, int len);
void	redlast(t_mult *m, char **argv, int argc);
void	execabso(char *path, char **args, char **env);
void	ft_kid2(char **argv, int argc, char **env, int *fdpipe);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_kid1(char **argv, char **env, int *fdpipe, char *buffer);
char	**checkfree(char **res, char *newstr, char *str, int mode);
void	ft_childfail(pid_t child, int *fd, char *lim, char *buffer);
void	multpipe(t_mult *m, int argc, char **argv, char **env);
char	*ft_strjoin(char *s1, char *s2, char *buffer);
void	here_doc(int argc, char **argv, char **env);
char	*parseput(char *lim, int argc, char **argv);
char	**ft_splitchars(char const *s, char c);
void	childfail(pid_t child, t_mult m);
char	*get_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	*gename(char *str, char *lim);
void	freeier(char *str, char *lim);
void	ft_putstr(char *str, int fd);
void	dup2failed(int fd, int mode);
char	**splitspaceargs(char *str);
int		ft_strchr(char *s, int c);
char	**ft_splitawk(char *str);
char	*get_next_line(int fd);
void	ft_puterror(char *str);
char	*trimbparse(char *str);
char	**ft_split(char *str);
char	*get_strdup(char *s1);
int		check_args(int argc);
int		ft_strlen(char *str);

#endif