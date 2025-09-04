/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:07:10 by enoshahi          #+#    #+#             */
/*   Updated: 2025/09/05 02:03:48 by enoshahi         ###   ########.fr       */
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

void	alphabetize_envs(t_env **temp, int size)
{
	int		i;
	int		j;
	t_env	*swap;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(temp[i]->key, temp[j]->key) > 0)
			{
				swap = temp[i];
				temp[i] = temp[j];
				temp[j] = swap;
			}
			j++;
		}
		i++;
	}
}

void	print_export(int size, t_env **exp)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (exp[i]->val)
			printf("declare -x %s=\"%s\"\n", exp[i]->key, exp[i]->val);
		else
			printf("declare -x %s\n", exp[i]->key);
		i++;
	}
}

void	export(char **envp, t_envs *envs, char *args)
{
	t_env	*temp;
	t_env	**exp;
	int		size;
	int		i;

	i = 0;
	(void)args;
	(void)envp;
	print_env(envp, envs, 0);
	size = env_size(envs->env);
	exp = malloc(sizeof(t_env *) * size);
	if (!exp)
		return ;
	temp = envs->env;
	while (temp)
	{
		exp[i++] = temp;
		temp = temp->next;
	}
	alphabetize_envs(exp, size);
	print_export(size, exp);
	free(exp);
}
