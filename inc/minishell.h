/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:31:56 by nikitos           #+#    #+#             */
/*   Updated: 2023/08/16 14:45:58 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>

# define WORD 0
# define PIPE 1 // |
# define SPAC 2 // ' '
# define GREATER_THAN 3 // >
# define LESS_THAN 4 // <
# define DOUBLE_QUOTES 5 // "
# define SINGLE_QUOTES 6 // '
# define HEREDOCK 7 // <<
# define APPEND 8 // >>
# define EXPANSION 9

typedef struct s_token_list
{
	int					len;
	char				*tok;
	int					type;
	int					corrective_token;
	int					i;
	int					k;
	struct s_token_list	*next;
	struct s_token_list	*prev;
}						t_token_list;

typedef struct s_pipe_group
{
	char				**argv;
	char				*cmd;
	int					fd[2];
	int					input;
	int					output;
	int					pipe_index;
	char				*heredoc;
	struct s_pipe_group	*next;
}						t_pipe_group;

typedef struct s_minishell
{
	char			**envp;
	int				error;
	int				current_env;
	int				last;
	t_pipe_group	*pipes;
}			t_minishell;

t_minishell *g_shell_h;

char				*read_input(void);
char				*get_word(char *str, int start, int end);
char				*find_in_env(char *str);

int					ft_lstsize_n(t_token_list *start, t_token_list *finish);
int					get_type(char symbol);
int					assign_env(char **envp);
int					define_malloc(int *i, int *j, char *inp);
char				*get_var_name(char *inp);

void				change_node(t_token_list *tmp, \
char *buf, t_token_list **list);
void				split_value(t_token_list **tmp, \
char *buf, t_token_list **list, int *type);
void				init_vars_env(int	*counter, char ***env, char **envp, int *i);
void				last_letter(t_token_list *list, \
char *buf, int sta, int end);
void				print_env(void);

void				ft_clear_tokens(t_token_list **tokens);
void				ft_lstadd_back_minishell(t_token_list **lst, \
t_token_list *new);
void				get_final_type(t_token_list **token);
void				check_quotes(t_token_list *tokens);
void				*find_words(char *input, t_token_list **list);
void				list_value_cmp(t_token_list **list);
void				list_value_split(t_token_list **list, int type);
void				pipe_grp_mmry(t_pipe_group **pipe_grp, t_token_list *start, t_token_list *finish);
void				parse(t_token_list *list);

t_token_list		*ft_put_between_token(t_token_list *prev, \
t_token_list*next, char *value);
t_token_list		*lexer(char *input);
t_token_list		*delete_spaces(char *str, int start, int end);
t_token_list		*create_token(int length, char *start, int type);
t_token_list		*ft_lstlast_minishell(t_token_list *lst);

t_pipe_group		*create_pipe_group(t_token_list *start, t_token_list *finish);
#endif