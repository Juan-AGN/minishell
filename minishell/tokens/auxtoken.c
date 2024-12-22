/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxtoken.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:41:23 by juan-ant          #+#    #+#             */
/*   Updated: 2024/12/19 13:56:35 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

int	ft_count_inout(char *input)
{
	int	i;

	i = 0;
	while (input[i] == '<' || input[i] == '>')
		i ++;
	while (input[i] <= 32 && input[i] >= 32)
		i ++;
	i += ft_count_token(&input[i]);
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
		if (input[i] == '"')
			while (input[i] != '"' && input[i] != '\0')
				i ++;
		else if (input[i] == 39)
			while (input[i] != 39 && input[i] != '\0')
				i ++;
		if (input[i] == '|')
			u ++;
		i ++; 
	}
	return (u + 1);
}

int	ft_params(char *input)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (input[i] != '|' && input[i] != '\0')
	{
		while (input[i] <= 32 && input[i] >= 1)
			i ++;
		if (input[i] == '<' || input[i] == '>')
			i += ft_count_inout(&input[i]);
		if (input[i - 1] == '"')
			while (input[i] != '"' && input[i] != '\0')
				i ++;
		else if (input[i] == '"')
			while (input[i] != 39 && input[i] != '\0')
				i ++;
		i ++;
		if (ft_spcharnospace_if(input[i] == 1))
			u ++;
	}
	return (u);
}
