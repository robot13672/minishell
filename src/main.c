/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:11:47 by nikitos           #+#    #+#             */
/*   Updated: 2023/08/16 14:49:52 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
	
	int i = 0;
	int j = 0;
	int size = define_malloc(&i, &j, "Hello$PATH");
	printf("%d", size);
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
	return (1);
}
