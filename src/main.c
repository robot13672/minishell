/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:11:47 by nikitos           #+#    #+#             */
/*   Updated: 2023/08/18 11:36:34 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_minishell	*g_shell_h = NULL;

void	init_main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	assign_env(env);
	//signals
}

int	main(int argc, char **argv, char **env)
{
	// t_token_list	*list;
	// char			*str;
	init_main(argc, argv, env);
	char *str = resolve_dollar("Xyi $LrANG HEll $USER");
	printf("%s\n", str);
	// printf("%d", size);
	// while (1)
	// {
	// 	str = read_input();
	// 	if (!str)
	// 		return (0);
	// 	// printf("%s\n", find_in_env(str));
	// 	// list = lexer(str);
	// 	// parse(list);
	// 	// ft_clear_tokens(&list);
	// }
	return (0);
}
