/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 04:09:02 by zcarde            #+#    #+#             */
/*   Updated: 2014/12/13 04:09:03 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i > 2)
		ft_putendl_fd("exit: too many arguments", 2);
	else if (i == 2)
		exit(ft_atoi(split[1]));
	else
		exit(0);
}
