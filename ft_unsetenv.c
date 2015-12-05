/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 04:09:22 by zcarde            #+#    #+#             */
/*   Updated: 2014/12/13 04:09:24 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**remalloc(char **split, int size)
{
	char	**ret;
	int		len;

	len = 0;
	while (split[len])
		len++;
	ret = (char **)malloc(sizeof(char *) * (len + size + 1));
	return (ret);
}

int		error_unsetenv_arg(int i)
{
	if (i < 2)
	{
		ft_putendl_fd("unsetenv: not enought arguments", 2);
		return (1);
	}
	else if (i > 2)
	{
		ft_putendl_fd("unsetenv: too many arguments", 2);
		return (1);
	}
	return (0);
}

void	ft_unsetenv(t_env *e, char **split)
{
	int		i;
	char	**env;
	int		j;

	i = 0;
	j = 0;
	while (split[i])
		i++;
	if (error_unsetenv_arg(i))
		return ;
	env = remalloc(e->env, -1);
	while (e->env[i])
	{
		if (ft_strncmp(split[1], e->env[i], ft_strlen(split[1])))
			env[j++] = ft_strdup(e->env[i]);
		i++;
	}
	env[j] = NULL;
	e->env = env;
	e->path = NULL;
	ft_get_env(e->env);
}

int		ft_tab_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
