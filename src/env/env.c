/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:31:26 by enoshahi          #+#    #+#             */
/*   Updated: 2025/09/05 02:04:03 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*env_malloc(char *to_copy, int len)
{
	int		i;
	char	*to_malloc;

	i = 0;
	to_malloc = malloc(sizeof(char) * (len + 1));
	if (!to_malloc)
		return (NULL);
	while (i < len)
	{
		to_malloc[i] = to_copy[i];
		i++;
	}
	to_malloc[i] = '\0';
	return (to_malloc);
}

// * collect the env info
t_env	*env_var_len(char *envp)
{
	t_env	*env;
	int		i;
	int		key_len;
	int		val_len;

	i = 0;
	val_len = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	key_len = i;
	if (envp[i] == '=')
		while (envp[++i])
			val_len++;
	env = malloc(sizeof(t_env));
	env->key = env_malloc(envp, key_len);
	if (!env->key)
		return (NULL);
	env->val = env_malloc(envp + key_len + 1, val_len);
	if (!env->val)
		return (NULL);
	env->next = NULL;
	return (env);
}

static t_env	*env_search(t_env *env, char *key_name)
{
	int		i;
	t_env	*tmp;

	tmp = env;
	if (key_name == NULL || key_name[0] == '\0')
		return (NULL);
	while (tmp)
	{
		i = 0;
		if (tmp->key)
		{
			while (tmp->key[i] && key_name[i] && tmp->key[i] == key_name[i])
				i++;
			if (tmp->key[i] == '\0' && key_name[i] == '\0')
				return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	print_env(char **envp, t_envs *environ, int flag)
{
	int		i;
	t_env	*new;

	i = 0;
	environ->env = NULL;
	while (envp[i])
	{
		new = env_var_len(envp[i]);
		if (new != NULL)
		{
			if (flag == 1)
				printf("%s=%s\n", new->key, new->val);
			env_search(environ->env, "USER");
			add_env(&environ->env, new);
		}
		i++;
	}
	envs_array(environ, environ->env);
}

// *  make new pointer = head
// *  use new pointer to search

// *  linked lst node->node->node->NULL
// *  			key	 key   key
// *  			val  val   val

// *  find variable by searching for key
// *  if found, return node, else null
