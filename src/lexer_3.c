/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:48:42 by ikhristi          #+#    #+#             */
/*   Updated: 2023/08/14 19:31:59 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	variable_expansion(t_token_list **token)
{
	t_token_list	*tmp;
	int				single_quotes;
	int				size;

	single_quotes = -1;
	tmp = token;
	while (tmp)
	{
		if (tmp->type == SINGLE_QUOTES)
			single_quotes = -single_quotes;
		if (ft_strchr(tmp->tok, '$'))
		{
			def
		}
	}
}

int	define_malloc_size(int *start, char *str)
{
	int		end;
	char	new_str;

	*start = 0;
	end = 0;
	while (str[*start] != '\0')
	{
		if (str[*start] == '$')
			new_str = find_in_env()
	}




}