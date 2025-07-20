/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:23:16 by enoshahi          #+#    #+#             */
/*   Updated: 2025/07/20 15:01:15 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

# define PROMPT "trash >> " 

// ! linked list for the environment variables
typedef struct s_env
{
	char			*key;
	char			*val;
	struct s_env	*next;
}	t_env;

// ! struct for all the environment data
typedef struct s_envs
{
	int		e_code; // * exit code
	int		shlvl; // * how many levels of shell your in
	char	*cwd; // * current working directory
	char	*owd; // * old working directory
	char	**path; // * all paths in $PATH
	char	**envs; // * our enviroment variables for execve
	t_env	*env; // * head for envs linked list
}	t_envs;

typedef struct s_exec
{
	char	**infiles;
	char	**outfiles;
}	t_exec;

typedef struct s_shell
{
	char	*user_input;
	t_envs	*envs;
}	t_shell;

enum e_token_types
{
	SPACES,
	WORD,
	ENV,
	PIPE,
	INPUT,
	HEREDOC,
	TRUNCATE,
	APPEND,
	INFILE,
	OUTFILE,
	END
};

// ! || FUNCTION PROTOTYPES ||

// * 	environment functions:
void	print_env(char **envp, t_envs *environ);

#endif