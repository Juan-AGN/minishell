/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleenvs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:34:01 by juan-ant          #+#    #+#             */
/*   Updated: 2024/11/11 13:32:05 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char    *ft_joinenv_doubles(char *str, char *tojoin)
{
	int		i;
	char	*current;
	char	*joined;

    i = 0;
	while (str[i] != 34 && str[i] != '\0' && str[i] != '$' && str[i] != 39 && str[i] != ' ')
		i ++;
	current = malloc(sizeof(char) * i);
	if (current == NULL)
		return (NULL);
	current = ft_strncpy(str, i - 1);
	joined = ft_strjoin(tojoin, current);
	if (joined == NULL)
		return (NULL);
	free(current);
	if (str[i] == '$')
		ft_joinenv(&str[i + 1], joined);
	return (joined);
}