/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlebasic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:00:26 by juan-ant          #+#    #+#             */
/*   Updated: 2024/11/08 16:05:28 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_paramtoken(t_shell *minishell, char *input, char *aux, int i)
{

}

int ft_commandtoken(t_shell *minishell, char *input, char *aux, int i)
{
	char	*dup;
	t_token	*new;

	dup = ft_strndup(aux, minishell->counter);
	if (dup == NULL)
		return (-1);
	new = ft_tokentnew("COMMAND", dup, NULL);
	if (new == NULL)
	{
		free(dup);
		return (-1);
	}
	ft_tokenadd_back(minishell->commands, new);
	minishell->current_token = new;
	return (1);
}

int	ft_checkcasses(t_shell *minishell, char *input, char *aux, int i)
{
	if ()
	else if ()
	else if (minishell->command_assign_aux == 0)
	{
		ft_commandtoken(minishell, input, aux, i);
		minishell->command_assign_aux = 1;
	}
	else
		return(ft_parantoken(minishell, input, aux, i, minishell->counter) + 1);
}

int	ft_handlebasic(t_shell *minishell, char *input, char *aux, int i)
{
	int	aux_int;

	minishell->counter = 0;
	minishell->command_assign_aux = 0;
	while (&aux[minishell->counter] < &input[i])
	{
		if (ft_specialchar_if(aux[minishell->counter]) == 1)
		{
			aux_int = ft_checkcasses(minishell, input, aux, i);
			if (aux_int == -1)
				return (-1);
			aux += minishell->counter + aux_int;
			minishell->counter = 0;
		}
		else
			minishell->counter ++;
	}
}
