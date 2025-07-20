/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:37:11 by enoshahi          #+#    #+#             */
/*   Updated: 2025/07/21 00:45:11 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_env(char **envp, t_envs *environ)
{
	int		i;
	t_env	*new;

	i = 0;
	environ->env = NULL;
	printf("\033[95muwu\033[0m\n");
	printf("\n\033[32m====================PRINTING \
ENVS====================\n\n\033[0m");
	while (envp[i])
	{
		new = env_var_len(envp[i]);
		if (new != NULL)
		{
			printf("--------\033[33mENV NO: %i\033[0m---------\n\033[95mKEY:\033\
[0m '%s'\n\033[36mVALUE:\033[0m'%s'\n", i + 1, new->key, new->val);
			add_env(&environ->env, new);
		}
		i++;
	}
	printf("\n\033[32m======================COMPLETED\
====================\n\033[0m\n");
}
