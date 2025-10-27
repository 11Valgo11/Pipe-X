/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimbparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:43:55 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/02/24 22:36:03 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	quotespace(char *str)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (str[i])
	{
		while (str[i] == ' ')
		{
			i++;
			if (str[i] == '\'')
			{
				i++;
				if (str[i] == '\'')
					space++;
				if (str[i] == ' ')
					space++;
			}
		}
		i++;
	}
	return (space);
}

int	quotenb(char *str)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			quote++;
		i++;
	}
	return (quote);
}

char	*trimbparse(char *str)
{
	char	*trimstr;
	int		quote;
	t_quo	quo;

	ft_bzero(&quo, sizeof(t_quo));
	if (quotespace(str) == 0 && !ft_strchr(str, '"') && str != NULL)
	{
		quote = quotenb(str);
		trimstr = malloc(ft_strlen(str) - quote + 1);
		if (!trimstr)
		{
			free(str);
			return (NULL);
		}
		while (str[quo.i])
		{
			if (str[quo.i] == '\'' || str[quo.i] == '"')
				quo.i++;
			else
				trimstr[quo.j++] = str[quo.i++];
		}
		trimstr[quo.j] = '\0';
		return (trimstr);
	}
	return (str);
}
