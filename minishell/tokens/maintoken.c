/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintoken.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:41:23 by juan-ant          #+#    #+#             */
/*   Updated: 2025/01/21 16:15:10 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_alloc_inout(int i, t_token *token, int mod)
{
	char	**toret;
	int		u;

	u = 0;
	if (mod == 1)
		token->ninfiles = i;
	else
		token->noutfiles = i;
	toret = malloc(sizeof(char **) * i);
	while (u != i)
	{
		toret[u] = NULL;
		u ++;
	}
	return (toret);
}

int	ft_in_out(t_shell *minishell, t_token *token, char *input, int i)
{
	int	u;

	u = 0;
	if (input[i] == '<')
	{
		if (token->infiles == NULL)
			token->infiles = ft_alloc_inout(ft_inoutcounter(&input[i], '<'), token, 1);
		while (token->ninfiles - ft_inoutcounter(&input[i], '<') > u)
			u ++;
		token->infiles[u] = ft_handle_inf(minishell, &input[i]);
	}
	else if (input[i] == '>')
	{
		if (token->outfiles == NULL)
			token->outfiles = ft_alloc_inout(ft_inoutcounter(&input[i], '>'), token, 2);
		while (token->noutfiles - ft_inoutcounter(&input[i], '>') > u)
			u ++;
		token->outfiles[u] = ft_handle_out(minishell, &input[i]);
	}
	return (ft_count_inout(&input[i]) + i);
}

int ft_createcommand(t_shell *minishell, t_token *token, char *input, int i)
{
	int u;

	u = 0;
	if (token->command == NULL)
	{
		token->command = ft_handleplain(minishell, &input[i], NULL);
		i += ft_count_token(&input[i]);
		token->nparams = ft_params(&input[i]);
		if (ft_params(&input[i]) != 0)
			token->params = malloc(sizeof(char *) * ft_params(&input[i]));
		if (token->command == NULL)
			return (i);
	}
	else
	{
		while (token->nparams - ft_params(&input[i]) > u)
			u ++;
		token->params[u] = ft_handleplain(minishell, &input[i], NULL);
		i += ft_count_token(&input[i]);
		printf("p%i| %s |\n", u, token->params[u]);
		if (token->params[u] == NULL)
			return (i + ft_count_token(&input[i]));
	}
	printf("%i | %s |\n", ft_count_token(&input[i]), token->command);
	return (i);
}

int	ft_alloctoken(int i, t_shell *minishell)
{
	int	u;

	u = 0;
	minishell->ncomands = i;
	minishell->token = malloc(sizeof(t_token) * i);
	if (minishell->token == NULL)
		return (-1);
	while (u < i)
	{
		minishell->token[u].command = NULL;
		minishell->token[u].params = NULL;
		minishell->token[u].infiles = NULL;
		minishell->token[u].outfiles = NULL;
		minishell->token[u].nparams = 0;
		minishell->token[u].ninfiles = 0;
		minishell->token[u].noutfiles = 0;
		u ++;
	}
	return (1);
}

int ft_maintoken(t_shell *minishell, char *input)
{
	int	i;
	int u;

	i = 0;
	u = 0;
	ft_alloctoken(ft_comands(input), minishell);
	while (input[i] != '\0')
	{
		if (ft_spcharparams_if(input[i]) == 0)
			i = ft_createcommand(minishell, &minishell->token[u], input, i);
		while (input[i] >= 1 && input[i] <= 32)
			i ++;
		if (input[i] == '<' || input[i] == '>')
			i = ft_in_out(minishell, &minishell->token[u], input, i);
		if (input[i] == '|')
		{
			if (minishell->token[u].command == NULL)
				return (ft_printf("bash: syntax error near unexpected token '%c'\n", input[i]));
			u ++;
			i ++;
		}
	}
	if (minishell->token[u].command == NULL)
		return (ft_printf("bash: syntax error near unexpected token `newline'\n"));
	return (0);
}