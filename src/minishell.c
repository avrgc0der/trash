/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:00:32 by mtangalv          #+#    #+#             */
/*   Updated: 2025/08/27 11:49:31 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_array(t_envs *env)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	while (env->envs[i])
	{
		printf("%s\n", env->envs[i]);
		i++;
	}
	
}

int	main(int argc, char **argv, char **envp)
{
	char	*user_input;
	t_envs	envs;

	(void)argc;
	(void)argv;
	(void)envp;
	print_env(envp, &envs);
	export(&envs, NULL);
	while (1)
	{
		user_input = readline(PROMPT);
		if (!user_input)
		{
			ft_printf("exit\n");
			break ;
		}
		if (*user_input)
		{
			add_history(user_input);
			ft_printf("You entered: %s\n", user_input);
			free(user_input);
		}
		else
			free(user_input);
	}
	return (0);
}
