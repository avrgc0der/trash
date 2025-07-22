/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:54:31 by enoshahi          #+#    #+#             */
/*   Updated: 2025/07/22 23:48:43 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_free_node(t_env *env)
{
	if (!env)
		return ;
	if (env->key)
		free(env->key);
	if (env->val)
		free(env->val);
	free(env);
}

void	env_free_all(t_envs *envs)
{
	int		i;
	t_env	*tmp;
	t_env	*current;

	current = envs->env;
	if (!envs)
		return ;
	while (current)
	{
		tmp = current->next;
		env_free_node(tmp);
		current = tmp;
	}
	envs->env = NULL;
	if (envs->envs)
	{
		i = 0;
		while (envs->envs[i])
		{
			free(envs->envs[i]);
			i++;
		}
		free(envs->envs);
		envs->envs = NULL;
	}
}
