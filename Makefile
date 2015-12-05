# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/23 18:16:14 by zcarde            #+#    #+#              #
#    Updated: 2015/02/19 09:46:44 by zcarde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1

SRC = ft_minishell.c ft_builtins.c is_space_or_tab.c strsplit_fn.c  ft_cd.c \
ft_cd2.c ft_check_bin.c ft_env.c ft_exit.c ft_get.c ft_setenv.c ft_unsetenv.c \
env_vars.c

OBJ = $(SRC:.c=.o)

#FLAG = -Wall -Werror -Wextra -ggdb3

LIBFT = libft -lft

INCLUDES = -I libft/includes

.PHONY : libft.a

all : libft.a $(NAME)

libft.a:
	@$(MAKE) -C ./libft

$(NAME) : $(OBJ)
	gcc $(OBJ) $(INCLUDES) -L$(LIBFT) -o $(NAME)

%.o: %.c
	gcc $(FLAG) $(INCLUDES) -c $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
