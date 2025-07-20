/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:31:26 by enoshahi          #+#    #+#             */
/*   Updated: 2025/07/20 21:25:43 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*env_malloc(char *to_copy, int len)
{
	int i;
	char *to_malloc;

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
static t_env	*env_var_len(char *envp)
{
	t_env	*env;
	int		i;
	int		key_len;
	int		val_len;
	int		val_start;

	i = 0;
	key_len = 0;
	val_len = 0;
	val_start = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	key_len = i;
	if (envp[i] == '=')
	{
		val_start = i + 1;
		while (envp[val_start + val_len])
			val_len++;
	}
	// * ========================================
	env = malloc(sizeof(t_env));
	env->key = env_malloc(envp, key_len);
	if (!env->key)
		return (NULL);
	env->val = env_malloc(envp + key_len + 1, val_len);
	if (!env->val)
		return (NULL);
	// * ========================================
	env->next = NULL;
	printf("%s=%s\n", env->key, env->val);
	return (env);
}

static t_env	*env_last(t_env *lst)
{
	t_env	*node;

	node = lst;
	if (!lst)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

static void	add_env(t_env **env, t_env *new)
{
	if (!env || !new)
		return ;
	if (*env)
		env_last(*env)->next = new;
	else
		*env = new;
}

static t_env	*env_search(t_env *env, char *key_name)
{
	int	i;
	t_env *tmp;

	tmp = env;
	// printf("\033[95muwu\033[0m\n");
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

// static void	modify_env(t_env *env, char *key_name, char *new_val)
// {
// 	t_env *tmp;

// 	tmp = env_search(env, key_name);
// 	if (!tmp)
// 		return ;
// 	free(tmp->val);
// 	tmp->val = ft_strdup(new_val);
// }
// *  modify_env(env, SHLVL, 4)

// * function to modify the value of an environment variable
// ! e.g.    SHLVL=1 -> SHLVL=2

// static void change_shlvl(t_env *env)
// {
// 	t_env	*tmp;
// 	char	*str;
// 	int		nb;
// 	tmp = env_search(env, "SHLVL");
// 	if (!tmp)
// 		return ; // * make sure to take care the no SHLVL case
// 	nb = ft_atoi(tmp->val);
// 	nb += 1;
// 	str = ft_itoa(nb);
// 	modify_env(tmp, "SHLVL", str);
// 	free(str);
// }

// * t_env *env -> char **envp

static int env_size(t_env *env)
{
	int	i;
	t_env *tmp;

	i = 0;
	tmp = env;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// static int array_size(char **array)
// {
// 	int i;
	
// 	i = 0;
// 	while (array[i])
// 		i++;
// 	return (i);
// }

char	*env_join(t_env *env)
{
	char	*joinstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	int len = ft_strlen(env->key) + ft_strlen(env->val) + 2;
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

// static char *return_key(t_env *node)
// {
// 	if (!node)
// 		return (NULL);
// 	return (node->key);
// }

// static char *return_val(t_env *node)
// {
// 	if (!node)
// 		return (NULL);
// 	return (node->val);
// }

void envs_array(t_envs *list_envs, t_env *env)
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

void	print_env(char **envp, t_envs *environ)
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
			// printf("%s=%s\n", new->key, new->val);
			env_search(environ->env, "USER");
			add_env(&environ->env, new);
		}
		i++;
	}
	// envs_array(environ, environ->env);
}


// *  make new pointer = head
// *  use new pointer to search

// *  linked lst node->node->node->NULL
// *  			key	 key   key
// *  			val  val   val

// *  find variable by searching for key
// *  if found, return node, else null

// static void	test_env(char **envp, t_envs *environ)
// {
// 	int		i;
// 	t_env	*new;
	
// 	i = 0;
// 	environ->env = NULL;
// 	printf("\n\033[32m====================PRINTING ENVS====================\n\n\033[0m");
// 	while (envp[i])
// 	{
// 		new = env_var_len(envp[i]);
// 		if (new != NULL)
// 		{
// 			printf("--------\033[33mENV NO: %i\033[0m---------\n\033[95mKEY:\033[0m '%s'\n\033[36mVALUE:\033[0m'%s'\n", i + 1, new->key, new->val);
// 			add_env(&environ->env, new);
// 		}
// 		i++;
// 	}
// 	printf("\n\033[32m======================COMPLETED====================\n\033[0m\n");
// }
