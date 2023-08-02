/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:23:45 by novsiann          #+#    #+#             */
/*   Updated: 2023/08/02 20:37:10 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *get_word(char *str, int start, int end)
{
	char 	*new_str;
	int		i;

	i = 0;
	new_str = malloc(sizeof(char) * (end - start + 1));
	if (!new_str)
		return (NULL);
	while (start < end)
		new_str[i++] = str[start++];
	new_str[i] = '\0';
	return (new_str);
}

//Iliya eto PIZDA!!!!!!!
void	list_value_split(t_token_list **list, int type)
{
	t_token_list	*tmp;
	int				start;
	int				end;
	char			*str;

	tmp = *list;
	start = 0;
	end = 0;
	while (tmp->tok[end] != '\0')
	{
		if(get_type(tmp->tok[end]) != type || tmp->tok[end + 1] == '\0')
		{
			if (tmp->tok[end + 1] == '\0')
				end++;
			str = get_word(tmp->tok, start, end);
			ft_put_between_token(tmp->prev, tmp->next, str);
			free(str);
			type = get_type(tmp->tok[end]);
			start = end;
		}
		end++;
	}
	tmp = *list;
	
	// while (splited_tokens != NULL)
	// {
	// 	printf("[%s]\n", splited_tokens->tok);
	// 	splited_tokens = splited_tokens->next;
	// }
}


void	list_value_check(t_token_list **list)
{
	int 			i;
	int 			type;
	t_token_list	*temp;

	temp = *list;
	while(temp != NULL)
	{
		i = 0;
		type = get_type(temp->tok[i]);
		while(temp->tok[i] != '\0')
		{
			if (get_type(temp->tok[i]) != type)
			{
				list_value_split(&temp, type);
				break ;
			}
			else
				i++;
		}
		temp = temp->next;
	}
}

t_token_list	*list_without_spaces(char *str, int start, int end)
{
	char *new_str;
	t_token_list *list;
	int tmp_start;
	int	i;

	i = 0;
	tmp_start = start;
	new_str = malloc(sizeof(char *) * (end - tmp_start + 1));
	if (!new_str)
		exit (0);
	while(tmp_start < end)
		new_str[i++] = str[tmp_start++];
	list = create_token(end - start, new_str, 1);
	return (list);
}

void	lexer(char *input)//
{
	int				start;
	int				end;
	t_token_list	*list;

	start = 0;
	end = 0;
	list = NULL;
	while (input[start])
	{
		while (((input[start] >= 8 && input[start] <= 14) || input[start] == 32) && input[start] != '\0')
			start++;
		end = start;
		while (!(input[start] >= 8 && input[start] <= 14) && input[end] != ' '  && input[end] != '\0')
			end++;
		if (!list)
			list = list_without_spaces(input, start, end);
		else if (input[start] != '\0' && input[start] != 32)
			ft_lstadd_back_minishell(&list, list_without_spaces(input, start, end));
		start = end;
	}
	list_value_check(&list);
	while(list != NULL)
	{
		printf("%s \n", list->tok);
		list = list->next;
	}
	// ft_clear_tokens(&list);
	write(1, "\n", 1);
	// return (list);
}
