/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintoken.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:41:23 by juan-ant          #+#    #+#             */
/*   Updated: 2024/12/16 18:32:19 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_specialchar_if(char c)
{
	if (c > 32 && c != '<' && c != '>' && c != '|')
		return (0);
	else
		return (1);
}

int	ft_count_token(char *input)
{
	int	i;

	i = 0;
	while (ft_specialchar_if(input[i]) != 1)
	{
		if (input[i] == '"')
		{
			i ++;
			while (input[i] != '"' && input[i] != '\0')
				i ++;
		}
		else if (input[i] == 39)
		{
			i ++;
			while (input[i] != 39 && input[i] != '\0')
				i ++;
		}
		if (ft_specialchar_if(input[i]) != 1)
			i ++;
	}
	return (i);
}

int	ft_comands(char *input)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	if (input[i] == '|')
		u ++;
	
	while (input[i] != '\0')
	{
		if (input[i - 1] == '"')
			while (input[i] != '"' && input[i] != '\0')
				i ++;
		else if (input[i] == '"')
			while (input[i] != 39 && input[i] != '\0')
				i ++;
		if (input[i] == '|')
			u ++;
		i ++; 
	}
	return (u + 1);
}

int ft_maintoken(t_shell *minishell, char *input)
{
	int	i;

	i = 0;
	printf("%i | COMANDS\n", ft_comands(input));
	printf("--|---------\n");
	minishell->token = malloc(sizeof(t_token) * ft_comands(input));
	while (input[i] != '\0')
	{
		while (input[i] >= 1 && input[i] <= 32)
			i ++;
		if (input[i] != '\0')
		{
			printf("%i | %s\n", ft_count_token(&input[i]), ft_handleplain(minishell, &input[i], NULL));
			i += ft_count_token(&input[i]);
		}
	}
	return (0);
}