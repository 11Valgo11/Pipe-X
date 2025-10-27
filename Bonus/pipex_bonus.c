/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-bou <ayel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:43:18 by ayel-bou          #+#    #+#             */
/*   Updated: 2025/02/25 21:25:16 by ayel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_mult	m;

	ft_bzero(&m, sizeof(t_mult));
	if (argc <= 2)
		exit(1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		here_doc(argc, argv, env);
	else
	{
		m.npipes = check_args(argc);
		m.j = 2;
		multpipe(&m, argc, argv, env);
	}
	return (0);
}
