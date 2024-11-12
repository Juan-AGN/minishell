/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublequotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:31:23 by juan-ant          #+#    #+#             */
/*   Updated: 2024/11/11 13:29:53 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_handledoubles(char *str, char *tojoin)
{
	int		i;
	char	*current;
	char	*joined;

	i = 0;
	while (str[i] != 34 && str[i] != '\0' && str[i] != '$')
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