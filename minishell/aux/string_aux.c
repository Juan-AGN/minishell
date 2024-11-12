/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:42:50 by juan-ant          #+#    #+#             */
/*   Updated: 2024/11/11 12:59:02 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*str;

	str = malloc(n + 1 * sizeof(char));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, s1, n + 1);
	str[n + 1] == '\0';
	return (str);
}