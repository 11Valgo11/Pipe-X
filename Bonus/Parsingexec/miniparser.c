/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:43:03 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/02/24 22:39:01 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static char	*removesep(char *str)
{
	int			i;
	int			j;
	char		*star;

	i = 0;
	j = 0;
	star = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!star)
		return (NULL);
	while (str[i] && j < ft_strlen(str))
	{
		if (str[i] == 0x1F)
			i++;
		star[j++] = str[i++];
	}
	star[j] = '\0';
	free(str);
	return (star);
}

static int	ft_parsestring(char *str)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			space++;
		i++;
	}
	return (space);
}

char	*addsep(char *str, t_split *sp)
{
	char	*newstr;

	newstr = (char *)malloc((sp->len + 1) * sizeof(char));
	if (!newstr)
	{
		free(str);
		return (NULL);
	}
	while (str[sp->i] && sp->j < sp->len)
	{
		if (str[sp->i] == '\'')
			sp->count++;
		if (str[sp->i] == ' ')
			sp->space++;
		if (str[sp->i] == ' ' && sp->count == 2 && sp->space >= 2)
		{
			sp->count = 0;
			sp->i++;
			newstr[sp->j] = 0x1F;
			sp->j++;
		}
		newstr[sp->j++] = str[sp->i++];
	}
	newstr[sp->j] = '\0';
	return (newstr);
}

void	sendsep(char **res, char *newstr, t_split *sp)
{
	free(newstr);
	if (res == NULL)
		return ;
	sp->i = 0;
	while (res[sp->i])
	{
		if (res[sp->i][0] == 0x1F)
		{
			res[sp->i] = removesep(res[sp->i]);
			if (res[sp->i] == NULL)
				ft_free(res);
		}
		sp->i++;
	}
}

char	**splitspaceargs(char *str)
{
	t_split		sp;
	char		**res;
	char		*newstr;

	if (!str)
		return (NULL);
	ft_bzero(&sp, sizeof(t_split));
	sp.len = ft_strlen(str);
	newstr = addsep(str, &sp);
	res = NULL;
	if (ft_strnstr(str, "awk", ft_strlen(str)))
		res = checkfree(res, newstr, str, 0);
	else if (ft_parsestring(str) == 2 && !ft_strnstr(str, "awk", 3))
		res = checkfree(res, newstr, str, 1);
	else
		res = checkfree(res, newstr, str, 2);
	sendsep(res, newstr, &sp);
	return (res);
}
