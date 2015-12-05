/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 04:08:43 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/19 09:48:31 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					search_bin(t_env e, char *bin)
{
	int				i;
	t_stat			stat;

	i = 0;
	lstat(bin, &stat);
	if ((!ft_strncmp(bin, "./", 2) || ft_strchr(bin, '/'))
										&& !access(bin, F_OK))
	{
		if (S_ISDIR(stat.st_mode) || access(bin, X_OK) == -1)
		{
			ft_putstr_fd("permission denied :", 2);
			ft_putendl_fd(bin, 2);
			return (-3);
		}
		return (-2);
	}
	if (e.path)
		while (e.path[i])
		{
			if (!access(ft_strjoin(e.path[i], ft_strjoin("/", bin)), X_OK))
				return (i);
			i++;
		}
	return (-1);
}

int					exec_bin_in_pwd(char *bin)
{
	int	len;

	len = ft_strlen(bin);
	if (len > 2)
		if (bin[0] == '.' && bin[1] == '/')
			return (1);
	return (0);
}

void				exec_bin(char *bin, char **av, t_env *e)
{
	int		i;
	char	*str;

	i = 0;
	while (av[i])
	{
		str = ft_replace(av[i], "~", getvar(e, "HOME"));
		if (str)
			av[i] = str;
		i++;
	}
	execve(bin, av, e->env);
}
