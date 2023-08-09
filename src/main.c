/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:11:47 by nikitos           #+#    #+#             */
/*   Updated: 2023/08/09 13:16:53 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_token_list	*list;
	char			*str;

	while (1)
	{
		str = read_input();
		if (!str)
			return (0);
		list = lexer(str);
		parse(list);
		ft_clear_tokens(&list);
	}
	return (1);
}

void	init_main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;

	//signals
}