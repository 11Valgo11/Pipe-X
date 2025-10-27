/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_helper3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:50:47 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/02/24 21:30:37 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_wordnum(char *str)
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

static char	*ft_extract(char *str, int wordlen, int start)
{
	char		*split;
	int			i;

	split = malloc(wordlen + 1);
	i = 0;
	while (i < wordlen)
	{
		split[i] = str[start + i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

static void	ft_wordlen(char *str, int *wordlen, int *i, int count)
{
	if (count == 0)
	{
		while ((str[*i] != ' ' && str[*i] != '\t'
				&& str[*i] != '\'') && str[*i])
		{
			(*wordlen)++;
			(*i)++;
		}
	}
	else
	{
		while (str[*i])
		{
			(*wordlen)++;
			(*i)++;
		}
	}
}

static void	ft_escape(char *str, int *i, int *start, int *wordlen)
{
	int	count;

	count = 0;
	if (count == 0)
	{
		while ((str[*i] == ' ' || str[*i] == '\t') && str[*i])
		{
			count++;
			(*i)++;
		}
	}
	*start = *i;
	*wordlen = 0;
	ft_wordlen(str, wordlen, i, count);
}

char	**ft_splitawk(char *str)
{
	t_splitv3	sp3;
	char		**split;

	ft_bzero(&sp3, sizeof(t_splitv3));
	sp3.wordnum = ft_wordnum(str);
	split = (char **)malloc((sp3.wordnum + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (str[sp3.i] && sp3.j < sp3.wordnum)
	{
		ft_escape(str, &sp3.i, &sp3.start, &sp3.wordlen);
		if (sp3.wordlen > 0)
		{
			split[sp3.j] = ft_extract(str, sp3.wordlen, sp3.start);
			if (!split[sp3.j])
			{
				ft_free(split);
				return (NULL);
			}
		}
		sp3.j++;
	}
	split[sp3.j] = NULL;
	return (split);
}
