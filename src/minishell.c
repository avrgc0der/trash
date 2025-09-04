/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:00:32 by mtangalv          #+#    #+#             */
/*   Updated: 2025/09/05 02:02:47 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_exec(char *user_input, int flag, char **envp, t_envs *envs)
{
	if (*user_input)
	{
		add_history(user_input);
		ft_printf("You entered: %s\n", user_input);
		if (ft_strcmp(user_input, "env") == 0)
		{
			flag = 1;
			print_env(envp, envs, flag);
		}
		if (ft_strcmp(user_input, "export") == 0)
			export(envp, envs, NULL);
		free(user_input);
	}
	else
		free(user_input);
}

int	main(int argc, char **argv, char **envp)
{
	char	*user_input;
	t_envs	envs;
	int		flag;

	(void)argc;
	(void)argv;
	(void)envp;
	flag = 0;
	while (1)
	{
		user_input = readline(PROMPT);
		if (!user_input)
		{
			ft_printf("exit\n");
			break ;
		}
		mini_exec(user_input, flag, envp, &envs);
	}
	return (0);
}
