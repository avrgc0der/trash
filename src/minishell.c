/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:00:32 by mtangalv          #+#    #+#             */
/*   Updated: 2025/07/20 13:35:09 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// @brief Main entry point for the Minishell
/// @param argc Argument count
/// @param argv Argument vector
/// @param envp Environment variables
/// @return Exit status

t_env	*env_var_len(char *envp)
{
	t_env	*env;
	int		i = 0;
	int		key_len = 0;
	int		val_len = 0;
	int		val_start = 0;

	while (envp[i] && envp[i] != '=')
		i++;
	key_len = i;
	if (envp[i] == '=')
	{
		val_start = i + 1;
		while (envp[val_start + val_len])
			val_len++;
	}
	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->key = malloc(sizeof(char) * (key_len + 1));
	if (!env->key)
		return (free(env), NULL);
	env->val = malloc(sizeof(char) * (val_len + 1));
	if (!env->val)
		return (free(env->key), free(env), NULL);
	i = 0;
	while (i < key_len)
	{
		env->key[i] = envp[i];
		i++;
	}
	env->key[i] = '\0';
	i = 0;
	while (i < val_len)
	{
		env->val[i] = envp[val_start + i];
		i++;
	}
	env->val[i] = '\0';
	env->next = NULL;
	printf("%s=%s\n", env->key, env->val);
	return (env);
}

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

// * seperator

void	print_env(char **envp, t_envs *environ)
{
	int	i;
	t_env *new;

	i = 0;
	while (envp[i])
	{
		new = env_var_len(envp[i]);
		// printf("skibidi\n");
		if (new != NULL)
			add_env(&environ->env, new);
		i++;
	}
}

// * 

int	main(int argc, char **argv, char **envp)
{
	char	*user_input;
	t_envs	environ;

	(void)argc;
	(void)argv;
	(void)envp;
	print_env(envp, &environ);
	while (1)
	{
		user_input = readline(PROMPT);
		if (!user_input)
		{
			ft_printf("exit\n");
			break ;
		}
		if (*user_input)
		{
			add_history(user_input);
			ft_printf("You entered: %s\n", user_input);
			free(user_input);
		}
		else
			free(user_input);
	}
	return (0);
}
