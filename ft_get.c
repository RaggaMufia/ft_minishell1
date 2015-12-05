/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 04:09:08 by zcarde            #+#    #+#             */
/*   Updated: 2014/12/13 04:09:09 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_get_path(char *str)
{
	char	**path;
	char	*pat;

	pat = ft_strchr(str, '=') + 1;
	path = ft_strsplit(pat, ':');
	return (path);
}

char	*ft_get_home(char *str)
{
	char	*home;

	home = ft_strchr(str, '=') + 1;
	return (home);
}

char	*ft_get_pwd(char *str)
{
	char	*pwd;

	pwd = ft_strchr(str, '=') + 1;
	return (pwd);
}

char	*ft_get_old_pwd(char *str)
{
	char	*old_pwd;

	old_pwd = ft_strchr(str, '=') + 1;
	return (old_pwd);
}

void	print_cmd_not_found(char *bin)
{
	ft_putstr_fd(bin, 2);
	ft_putstr_fd(": command not found\n", 2);
}
