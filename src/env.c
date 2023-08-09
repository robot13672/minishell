/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:55:57 by ikhristi          #+#    #+#             */
/*   Updated: 2023/08/09 13:46:05 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_vars_env(int	*counter, char ***env, char **envp, int i;)
{
	*counter = 0;
	*i = 0;
	g_shell = malloc(sizeof(t_minishell));
	*env = malloc(sizeof(char *) * 1000);
	if (!env)
		return ;
	while (envp[*counter])
		(*counter)++;
}

int	assign_env(char **envp)
{
	int		count;
	char	**env;
	int		i;

	init_vars_env(count, env, envp, i);
	while (i < count)
	{
		env[i] = ft_strdup(envp[i]);
		if (!env[i])
			return ;
		i++;
	}
	envp[i] = NULL;
	g_shell->envp = env;



}
