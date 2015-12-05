/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 04:08:57 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/19 09:48:43 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_env_var(char *var, t_env *env)
{
	if (!ft_strncmp(var, "PATH", 4))
		env->path = ft_get_path(var);
}

t_env	ft_get_env(char **environ)
{
	t_env	env;
	int		i;

	env.env = environ;
	i = 0;
	while (environ[i])
	{
		ft_get_env_var(environ[i], &env);
		i++;
	}
	if (i == 0)
	{
		ft_putendl_fd("environnement not set", 2);
		exit(1);
	}
	return (env);
}

void	ft_env(t_env *e, char **split)
{
	int	i;
	int size;

	size = 0;
	i = 0;
	while (split[size])
		size++;
	if (size > 1)
		ft_putendl_fd("env: too many arguments", 2);
	while (e->env[i])
	{
		ft_putendl(e->env[i]);
		i++;
	}
}
