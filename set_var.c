/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 19:48:10 by zcarde            #+#    #+#             */
/*   Updated: 2014/12/16 19:48:19 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setvar(t_env *e, char *var, char *value)
{
	int		i;

	i = 0;
	while (e->env[i])
	{
		if (!ft_strncmp(e->env[i], var, ft_strlen(var)))
			e->env[i] = ft_strdup(ft_strjoin(var, ft_strjoin("=", value)));
		i++;
	}
}
