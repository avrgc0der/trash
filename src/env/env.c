/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:31:26 by enoshahi          #+#    #+#             */
/*   Updated: 2025/07/07 16:12:23 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// * collect the env info

t_env *get_envs(t_env *list, char **envp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		while (envp[i][j])
		{
			if (envp[i][j] == '=')
			{
				list->key = envp[i][j];
				break;
			}
			j++;
		}
		while (envp[i][j])
		{
			if (envp[i][j] == '\n')
			{
				list->val = envp[i][j];
				break;
			}
			j++;
		}
		i++;
	}
}

// ! "COOK INTER-MENTION" - tarek
// ! "4 CHICES OF SLEESE" - tarek


//* store each line in a node
//* 	- variable name		-> string
//* 	- variable value	-> string

//* - store linked list
//* - create helper functions
	
//TODO 	- check env if valid
//TODO 	- add variable 		-> export
//TODO 	- deletes variable	-> unset
//TODO 	- finds variable
//TODO 	- manipulate a variable's value
//TODO 	- print env		-> env
//TODO 	- print export		-> export
//TODO 	- change shlvl
//TODO 	- make 2d array
//TODO 	- get list length
//TODO 	- get array length
//TODO 	- get key/var name
//TODO 	- lst functions
//TODO 	- popping function
//TODO 	- get path
//TODO 	- create new variable