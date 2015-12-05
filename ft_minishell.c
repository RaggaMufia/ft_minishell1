/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 07:34:18 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/19 09:50:35 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_father;

void	check_bin(char *str, t_env *e)
{
	t_bin	bin;
	char	**av;
	int		i_path;

	av = strsplit_fn(str, &is_space_or_tab);
	bin.bin_name = av[0];
	if ((i_path = search_bin(*e, bin.bin_name)) >= 0)
		bin.path_bin = ft_strjoin(e->path[i_path],
				ft_strjoin("/", bin.bin_name));
	else if (i_path == -2)
		bin.path_bin = bin.bin_name;
	else if (i_path == -3)
		return ;
	else
	{
		print_cmd_not_found(bin.bin_name);
		return ;
	}
	g_father = fork();
	if (g_father == 0)
		exec_bin(bin.path_bin, av, e);
	else
		wait(0);
}

void	sighandler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\n");
		if (g_father == 0)
			kill(0, 0);
		if (g_father >= 5)
			ft_putstr("NEO>");
	}
	else if (g_father == 0)
		signal(sig, sighandler);
}

void	run(t_env *e)
{
	char	*line;

	ft_putstr("NEO>");
	g_father = 5;
	while (get_next_line(0, &line))
	{
		line = ft_strtrim(line);
		if (!line)
			exit(-1);
		if (ft_strcmp(line, ""))
		{
			if (is_builtin(line))
				builtin(line, e);
			else
				check_bin(line, e);
			ft_bzero(line, ft_strlen(line));
		}
		ft_putstr("NEO>");
	}
}

int		main(int ac, char **av, char **environ)
{
	t_env	env;

	(void)ac;
	(void)av;
	if (!isatty(0))
	{
		ft_putstr("NO");
		return (-1);
	}
	signal(SIGINT, sighandler);
	env = ft_get_env(environ);
	run(&env);
	return (0);
}
