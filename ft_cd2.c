/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 04:08:33 by zcarde            #+#    #+#             */
/*   Updated: 2014/12/13 04:08:34 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_replace(t_env *e, char **split)
{
	char	*pwd;

	pwd = ft_replace(getvar(e, "PWD"), split[1], split[2]);
	if (!pwd)
		cd_err(4, split[1]);
	else if (!ft_strcmp(pwd, getvar(e, "PWD")))
		return ;
	else if (chdir(pwd) == -1)
		cd_err(get_cd_error(pwd), pwd);
	else
	{
		setvar(e, "OLDPWD", getvar(e, "PWD"));
		setvar(e, "PWD", pwd);
	}
}

void	cd_old_pwd(t_env *e)
{
	chdir(getvar(e, "OLDPWD"));
	setvar(e, "OLDPWD", getvar(e, "PWD"));
	setvar(e, "PWD", getcwd(NULL, 0));
}

void	cd_normal(t_env *e, char *pwd)
{
	char	*newpwd;

	if (ft_strlen(pwd) == 1 && pwd[0] == '.')
		return ;
	newpwd = ft_replace(pwd, "~", getvar(e, "HOME"));
	if (newpwd == NULL)
		newpwd = ft_strdup(pwd);
	if (!ft_strcmp(newpwd, getvar(e, "PWD")))
		return ;
	if (chdir(newpwd) == -1)
		cd_err(get_cd_error(newpwd), newpwd);
	setvar(e, "OLDPWD", getvar(e, "PWD"));
	setvar(e, "PWD", getcwd(NULL, 0));
}

void	cd_arg(t_env *e, char **split)
{
	if (ft_strlen(split[1]) == 1 && split[1][0] == '-')
		cd_old_pwd(e);
	else if (ft_strlen(split[1]) == 2 && !ft_strcmp(split[1], "--"))
		cd_home(e);
	else
		cd_normal(e, split[1]);
}

void	cd_home(t_env *e)
{
	if (!ft_strcmp(getvar(e, "HOME"), getvar(e, "PWD")))
		return ;
	chdir(getvar(e, "HOME"));
	setvar(e, "OLDPWD", getcwd(NULL, 0));
	setvar(e, "PWD", getvar(e, "HOME"));
}
