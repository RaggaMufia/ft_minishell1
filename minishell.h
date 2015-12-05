/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 07:34:59 by zcarde            #+#    #+#             */
/*   Updated: 2015/01/28 00:28:22 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/stat.h>
# include <stdlib.h>
# include <dirent.h>
# include <unistd.h>
# include <signal.h>

typedef struct	s_env
{
	char		**path;
	char		**env;
}				t_env;

typedef struct	s_bin
{
	char		*bin_name;
	char		*path_bin;
}				t_bin;

typedef struct stat	t_stat;

char			**strsplit_fn(char const *s, int (*f) (char));

int				is_space_or_tab(char c);

void			set_var(t_env *e, char *var, char *value);
int				check_set_env(t_env *e, char **split);
void			add_env_var(t_env *e, char **split);
int				error_setenv_arg(int i);
void			ft_setenv(t_env *e, char **split);

char			**remalloc(char **split, int size);
int				error_unsetenv_arg(int i);
void			ft_unsetenv(t_env *e, char **split);
int				ft_tab_len(char **split);

void			ft_exit(char **split);

char    *ft_replace(char *src, char *str1, char *str2, int pos);
void			cd_err(int err, char *file);
void			replace_pwds(t_env *e, char *pwd);
int				get_cd_error(char *pwd);
void			ft_cd(t_env *e, char **split);

void			run_replace(t_env *e, char **split);
void			cd_old_pwd(t_env *e);
void			cd_normal(t_env *e, char *pwd);
void			cd_arg(t_env *e, char **split);
void			cd_home(t_env *e);

int				is_builtin(char *bin);
void			builtin(char *bin, t_env *env);

void			ft_get_env_var(char *var, t_env *env);
t_env			ft_get_env(char **environ);
void			ft_reinit_env_vars(t_env *e);
void			ft_env(t_env *e, char **split);

int				search_bin(t_env e, char *bin);
int				exec_bin_in_pwd(char *bin);
int				is_bin_in_dir(char *bin, char *pwd, int inpwd);
void			exec_bin(char *bin, char **av, t_env *e);

void			check_bin(char *str, t_env *e);
void			sighandler(int sig);
void			run(t_env *e);
int				main(int ac, char **av, char **environ);

char			**ft_get_path(char *str);
char			*ft_get_home(char *str);
char			*ft_get_pwd(char *str);
char			*ft_get_old_pwd(char *str);
void			print_cmd_not_found(char *bin);

char			*getvar(t_env *e, char *var);
void			setvar(t_env *e, char *var, char *value);

#endif
