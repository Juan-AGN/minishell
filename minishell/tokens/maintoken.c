/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintoken.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:41:23 by juan-ant          #+#    #+#             */
/*   Updated: 2024/12/19 13:56:35 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_maintoken(t_shell *minishell, char *input)
{
	int	i;
	int u;

	i = 0;
	u = 0;
	printf("%i | COMANDS\n", ft_comands(input));
	printf("--|---------\n");
	minishell->token = malloc(sizeof(t_token) * ft_comands(input));
	while (input[i] != '\0')
	{
		if (input[i] != '\0' && input[i] != '|' && input[i] > 32)
		{
			minishell->token[u].command = ft_handleplain(minishell, &input[i], NULL);
			printf("%i | %s |\n", ft_count_token(&input[i]), minishell->token[u].command);
			i += ft_count_token(&input[i]);
		}
		while (input[i] >= 1 && input[i] <= 32)
			i ++;
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