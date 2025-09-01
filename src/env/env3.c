/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:07:10 by enoshahi          #+#    #+#             */
/*   Updated: 2025/08/27 11:55:53 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//TODO 	- add variable 		-> export
// *  funct that returns void, recieves key and val, then adds to the list

void	env_create_var(t_env *env, char *key, char *val)
{
	t_env	*new;

	new = NULL;
	if (!key || !val)
		return ;
	new->key = ft_strdup(key);
	new->val = ft_strdup(val);
	add_env(&env, new);
}

//TODO 	- print export		-> export

void	alphabetize_envs(t_envs *envs)
{
	// * go through 
}

void	export(t_envs *envs, char *args)
{
	t_env	*temp;
	(void)args;

	temp = envs->env;
	while (temp->next)
	{
		printf("declare -x %s=\"%s\"\n", temp->key, temp->val);
		temp = temp->next;
	}
}
// * IF `export` with NO arguments
// * sort by alpha, adds `declare -x KEY="VAL"`

// * declare -x SHELL="/bin/bash"
// * SHELL=/bin/bash