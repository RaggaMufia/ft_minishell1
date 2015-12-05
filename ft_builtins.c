/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 14:43:06 by zcarde            #+#    #+#             */
/*   Updated: 2015/01/28 00:25:48 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_builtin(char *bin)
{
	char	**split;

	split = strsplit_fn(bin, &is_space_or_tab);
	bin = split[0];
	if (!ft_strcmp(bin, "exit"))
		return (1);
	else if (!ft_strcmp(bin, "cd"))
		return (1);
	else if (!ft_strcmp(bin, "unsetenv"))
		return (1);
	else if (!ft_strcmp(bin, "setenv"))
		return (1);
	else if (!ft_strcmp(bin, "env"))
		return (1);
	return (0);
}

void	builtin(char *bin, t_env *env)
{
	char	**split;

	split = strsplit_fn(bin, &is_space_or_tab);
	bin = split[0];
	if (!ft_strcmp(bin, "exit"))
		ft_exit(split);
	else if (!ft_strcmp(bin, "cd"))
		ft_cd(env, split);
	else if (!ft_strcmp(bin, "unsetenv"))
		ft_unsetenv(env, split);
	else if (!ft_strcmp(bin, "setenv"))
		ft_setenv(env, split);
	else if (!ft_strcmp(bin, "env"))
		ft_env(env, split);
}
