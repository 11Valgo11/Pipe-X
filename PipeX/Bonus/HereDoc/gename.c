/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gename.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:42:39 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/03/04 21:38:48 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static int	absolute(int n)
{
	if (n >= 0)
		return (n);
	return (n * (-1));
}

static int	nlen(long int n)
{
	int	lenght;

	lenght = 0;
	if (n < 0)
	{
		lenght = 1;
		n *= -1;
	}
	if (n == 0)
		lenght = 1;
	while (n > 0)
	{
		lenght++;
		n /= 10;
	}
	return (lenght);
}

static char	*putting(char *s, int lenght, int j, int n)
{
	int	i;

	i = lenght - 1;
	while (j++ < lenght)
	{
		s[i--] = absolute((n % 10)) + '0';
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*ascii;
	int		lenght;
	int		j;

	j = 0;
	lenght = nlen(n);
	ascii = malloc(lenght + 1);
	if (!ascii)
		return (NULL);
	if (n < 0)
	{
		ascii[0] = '-';
		j = 1;
	}
	if (n == 0)
		ascii[0] = n + '0';
	putting(ascii, lenght, j, n);
	ascii[lenght] = '\0';
	return (ascii);
}

char	*gename(char *str, char *lim)
{
	long	n;
	int		*nb;

	nb = malloc(sizeof(int *));
	if (!nb)
	{
		free(lim);
		ft_puterror("failed to generate buffer file name\n");
		exit(1);
	}
	n = (long)nb;
	str = ft_itoa(n);
	free(nb);
	return (str);
}
