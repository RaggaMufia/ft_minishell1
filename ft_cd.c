/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 04:08:24 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/25 10:58:19 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_replace(char *src, char *str1, char *str2, int pos)
{
	char	*str;
	char	*begin;
	int		i;
	int		len;
	int		final_len;

	i = 0;
	final_len = ft_strlen(src) - (ft_strlen(str1) - ft_strlen(str2));
	str = (char *)malloc(sizeof(char) * final_len);
	if (!str || !ft_strstr(src, str1))
		return (NULL);
	str = ft_strcpy(str, src);
	begin = ft_strstr(str + pos, str1);
	while (str2[i])
	{
		begin[i] = str2[i];
		i++;
	}
	len = begin - str + ft_strlen(str1);
	while (src[len])
		begin[i++] = src[len++];
	str[final_len] = '\0';
	return (str);
}

void	cd_err(int err, char *file)
{
	if (err == 1)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(file, 2);
	}
	else if (err == 2)
	{
		ft_putstr_fd("cd: not a directory: ", 2);
		ft_putendl_fd(file, 2);
	}
	else if (err == 3)
	{
		ft_putstr_fd("cd: permission denied: ", 2);
		ft_putendl_fd(file, 2);
	}
	else if (err == 4)
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putendl_fd(file, 2);
	}
}

int		get_cd_error(char *pwd)
{
	struct stat		st;
	int				ret;

	ret = lstat(pwd, &st);
	if (ret == 0 && (access(pwd, R_OK) == -1))
		return (3);
	else if (ret == 0 && S_ISDIR(st.st_mode) == 0)
		return (2);
	return (1);
}

void	ft_cd(t_env *e, char **split)
{
	int		i;

	i = 0;
	while (split[i])
		i++;
	if (i > 3)
		ft_putendl_fd("cd: too many arguments", 2);
	else
	{
		if (i == 3)
			run_replace(e, split);
		else if (i == 1)
			cd_home(e);
		else
			cd_arg(e, split);
	}
}
