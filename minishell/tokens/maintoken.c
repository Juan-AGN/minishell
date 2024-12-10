/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintoken.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:41:23 by juan-ant          #+#    #+#             */
/*   Updated: 2024/12/03 13:08:23 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_specialchar_if(char c)
{
	if (c > 32 || c != '<' || c != '>' && c != '|')
		return (1);
	else
		return (0);
}

int	ft_handle_pipe_error(char *input)
{
	if (*input == '|')
	{
		printf("bash: syntax error near unexpected token `|'\n");
		return (-1);
	}
	return (0);
}

int	ft_handle_token(t_shell *minishell, char *input, char *aux, int i)
{
	if (i == 0)
		if (ft_handle_pipe_error == -1)
			return (-1);
	ft_handlebasic(minishell, input, aux, i);
	if (*input == '\0')
		return (0);
	if (*input == '<')
		ft_handleinfile(minishell, input, aux, i);
	else if (*input == '>')
		ft_handleoutfile(minishell, input, aux, i);
	else if (*input == '|')
		ft_handlepipeline(minishell, input, aux, i);
}

int ft_maintoken(t_shell *minishell, char *input)
{
	int		i;
	char	*aux;
	int		result;

	i = 0;
	minishell->pipes = 0;
	while (input[i] != '\0')
	{
		aux = &input[i];
		while (ft_specialchar_if(input[i]))
			i ++;
		result = ft_handle_token(minishell, input, aux, i);
		if (result == -1)
			return (-1);
		i += result;
	}
	return (0);
}