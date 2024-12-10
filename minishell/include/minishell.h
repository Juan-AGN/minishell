/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:57:54 by juan-ant          #+#    #+#             */
/*   Updated: 2024/12/10 17:01:09 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>

typedef struct t_shell
{
	struct t_env	**env;
	struct t_token	**token;
	struct t_token	*current_token;
	int     		pipes;
	int				commands;
	int     		command_assign_aux;
	int				counter;
}	t_shell;

typedef struct t_env
{
	char			*name;
	char			*content;
	struct t_env	*next;
}	t_env;

typedef struct t_token
{
	char			*type; // COMMAND, PARAMETER, PIPELINE, INFILE
	char			*content; // CD      -a          |        <
	struct t_token	*param; //            x
	struct t_token	*next; //    x                   x
	struct t_token	*child; //                                x 
}	t_token;

//start
t_shell		*ft_prepare_values(char **envp);
//end start

//list
int			ft_plstsize(t_env *lst);

t_env		*ft_plstnew(char *name, char *content);

t_env		*ft_plstlast(t_env *lst);

void		ft_plstadd_front(t_env **lst, t_env *new);

void		ft_plstadd_back(t_env **lst, t_env *new);

t_env		*ft_lstadvance(t_env *lst, int i);

char		*ft_plstsearch(t_env *lst, char *name);
//end list

//free
t_shell		*ft_mass_free(void *value1, void *value2, void *value3, void *value4);

int			ft_plstclear(t_env **lst);
//end free

//miscelanious
char		*ft_get_env(char *str);

int			ft_specialchar_if(char c);
//end miscelanious

//token preparation
int	ft_handlebasic(t_shell *minishell, char *input, char *aux, int i);
//end token preparation

//tokens list control
int			ft_tokensize(t_token *lst);

t_token		*ft_tokentnew(char *type, char *content, char *child);

t_token		*ft_tokenlast(t_token *lst, int mode);

t_token		*ft_tokenadvance(t_token *lst, int advance);

void		ft_tokenadd_back(t_token **lst, t_token *new);
//end token list control

//string manip and aux functions
char		*ft_strndup(const char *s1, int n);
//end string mip and aux functions

//double ""
char	*ft_handledoubles(t_shell *minishell, char *str, char *tojoin);
//end of double ""

//single ''
char	*ft_handlesingles(char *str);
//end of single ''

//esp envs
char	*ft_strjoinenv(t_shell *minishell, char *tojoin, char *env);

int		ft_return_lenght(char *str);
//end esp envs

//plain text
char	*ft_handleplain(t_shell *minishell, char *str, char *tojoin);
//end plain text

#endif