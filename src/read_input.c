/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:53:49 by novsiann          #+#    #+#             */
/*   Updated: 2023/09/03 21:48:14 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*read_input(void)
{
	char	cwd[256];
	char	*ret;

	getcwd(cwd, sizeof(cwd));
	ft_strlcat(cwd, " : ", 256);
	ret = readline(cwd);
	if (ret && *ret)
		add_history(ret);
	return (ret);
}
