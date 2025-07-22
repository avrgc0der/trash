/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 23:59:07 by enoshahi          #+#    #+#             */
/*   Updated: 2025/07/22 21:01:24 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	modify_env(t_env *env, char *key_name, char *new_val)
{
	t_env	*tmp;

	tmp = env_search(env, key_name);
	if (!tmp)
		return ;
	free(tmp->val);
	tmp->val = ft_strdup(new_val);
}

void	change_shlvl(t_env *env)
{
	t_env	*tmp;
	char	*str;
	int		nb;

	tmp = env_search(env, "SHLVL");
	if (!tmp)
		return ;
	nb = ft_atoi(tmp->val);
	nb += 1;
	str = ft_itoa(nb);
	modify_env(tmp, "SHLVL", str);
	free(str);
}

int	array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static char	*return_key(t_env *node)
{
	if (!node)
		return (NULL);
	return (node->key);
}

static char	*return_val(t_env *node)
{
	if (!node)
		return (NULL);
	return (node->val);
}
