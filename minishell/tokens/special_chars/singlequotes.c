/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singlequotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:00:44 by juan-ant          #+#    #+#             */
/*   Updated: 2024/12/02 13:04:29 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#include "../../include/minishell.h"

char	*ft_handlesingles(char *str)
{
	int		i;
	char	*current;

	i = 0;
	while (str[i] != 39 && str[i] != '\0')
		i ++;
	current = malloc(sizeof(char) * i);
	if (current == NULL)
		return (NULL);
	ft_strlcpy(current, str, i + 1);
	return (current);
}