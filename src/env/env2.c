/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:11:11 by enoshahi          #+#    #+#             */
/*   Updated: 2025/07/21 00:18:20 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_last(t_env *lst)
{
	t_env	*node;

	node = lst;
	if (!lst)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	add_env(t_env **env, t_env *new)
{
	if (!env || !new)
		return ;
	if (*env)
		env_last(*env)->next = new;
	else
		*env = new;
}

int	env_size(t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	*env_join(t_env *env)
{
	char	*joinstr;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(env->key) + ft_strlen(env->val) + 2;
	joinstr = (char *)malloc((len) * sizeof(char));
	if (!joinstr)
		return (NULL);
	while (env->key[i] != '\0')
	{
		joinstr[i] = env->key[i];
		i++;
	}
	joinstr[i] = '=';
	i += 1;
	while (env->val[j] != '\0')
		joinstr[i++] = env->val[j++];
	joinstr[i] = '\0';
	return (joinstr);
}

void	envs_array(t_envs *list_envs, t_env *env)
{
	t_env	*tmp;
	int		size;
	int		i;

	i = 0;
	tmp = env;
	size = env_size(env);
	list_envs->envs = malloc(sizeof(char *) * (size + 1));
	while (tmp)
	{
		list_envs->envs[i] = env_join(tmp);
		i++;
		tmp = tmp->next;
	}
	list_envs->envs[i] = NULL;
}
