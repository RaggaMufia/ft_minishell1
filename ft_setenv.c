/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 04:09:14 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/19 09:49:30 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_var(t_env *e, char *var, char *value)
{
	int		i;

	i = 0;
	while (e->env[i])
	{
		if (!ft_strncmp(e->env[i], var, ft_strlen(var)))
			e->env[i] = ft_strjoin(var, ft_strjoin("=", value));
		i++;
	}
}

int		check_set_env(t_env *e, char **split)
{
	int		i;

	i = 0;
	while (e->env[i])
	{
		if (!ft_strncmp(e->env[i], split[1], ft_strlen(split[1])))
			return (i);
		i++;
	}
	return (-1);
}

void	add_env_var(t_env *e, char **split)
{
	int		j;
	char	**env;

	j = 0;
	env = remalloc(e->env, 1);
	env[ft_tab_len(e->env)] = ft_strjoin(split[1], ft_strjoin("=", split[2]));
	while (e->env[j])
	{
		env[j] = e->env[j];
		j++;
	}
	e->env = env;
}

int		error_setenv_arg(int i)
{
	if (i < 3)
	{
		ft_putendl_fd("setenv: not enought arguments", 2);
		return (1);
	}
	else if (i > 4)
	{
		ft_putendl_fd("setenv: too many arguments", 2);
		return (1);
	}
	return (0);
}

void	ft_setenv(t_env *e, char **split)
{
	int		i;
	int		modify;
	int		i_modify;

	i = 0;
	modify = 0;
	while (split[i])
		i++;
	if (error_setenv_arg(i))
		return ;
	if (i == 4)
		modify = ft_atoi(split[3]);
	i_modify = check_set_env(e, split);
	if (i_modify != -1 && modify == 0)
		return ;
	if (i_modify == -1)
		add_env_var(e, split);
	else
		e->env[i_modify] = ft_strjoin(split[1], ft_strjoin("=", split[2]));
	*e = ft_get_env(e->env);
}
