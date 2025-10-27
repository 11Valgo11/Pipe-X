/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:42:20 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/02/23 20:44:15 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	ft_wordnum(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		num++;
		while ((str[i] != ' ' && str[i] != '\t') && str[i])
			i++;
	}
	return (num);
}

char	*ft_extract(char *str, int wordlen, int start)
{
	char	*split;
	int		i;

	split = malloc(wordlen + 1);
	if (!split)
		return (NULL);
	i = 0;
	while (i < wordlen)
	{
		split[i] = str[start + i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

void	ft_wordlen(char *str, int *wordlen, int *i)
{
	while ((str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\'') && str[*i])
	{
		(*wordlen)++;
		(*i)++;
	}
	if (str[*i] == '\'')
	{
		while (str[*i])
		{
			(*wordlen)++;
			(*i)++;
			if (str[*i] == 0x1F)
				break ;
		}
	}
}

void	ft_escape(char *str, int *i, int *start, int *wordlen)
{
	while ((str[*i] == ' ' || str[*i] == '\t') && str[*i])
		(*i)++;
	*start = *i;
	*wordlen = 0;
	ft_wordlen(str, wordlen, i);
}

char	**ft_split(char *str)
{
	t_splitv2	v;
	char		**split;

	ft_bzero(&v, sizeof(t_splitv2));
	v.wordnum = ft_wordnum(str);
	split = (char **)malloc((v.wordnum + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (str[v.i] && v.j < v.wordnum)
	{
		ft_escape(str, &v.i, &v.start, &v.wordlen);
		if (v.wordlen > 0)
		{
			split[v.j] = ft_extract(str, v.wordlen, v.start);
			if (!split[v.j])
			{
				ft_free(split);
				return (NULL);
			}
		}
		v.j++;
	}
	split[v.j] = NULL;
	return (split);
}
