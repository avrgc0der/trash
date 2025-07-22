/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:07:10 by enoshahi          #+#    #+#             */
/*   Updated: 2025/07/22 23:49:31 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//TODO 	- add variable 		-> export
// *  funct that returns void, recieves key and val, then adds to the list

void	env_create_var(t_env *env, char *key, char *val)
{
	t_env	*new;

	if (!new || !key || !val)
		return ;
	new->key = ft_strdup(key);
	new->val = ft_strdup(val);
	add_env(&env, new);
}

//TODO 	- print export		-> export
int	strchr_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	export(t_envs *envs)
{
	char	**tmp;
	int		i;
	int		key_len;

	i = 0;
	tmp = envs->envs;
	key_len = strchr_len(tmp, '=');
	while (tmp[i])
	{
	}
	printf("declare -x %s=\"%s\"", new->key, new->val);
}
// * IF `export` with NO arguments
// * sort by alpha, adds `declare -x KEY="VAL"`

// * declare -x SHELL="/bin/bash"
// * SHELL=/bin/bash