/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokencontrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ant <juan-ant@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:18:18 by juan-ant          #+#    #+#             */
/*   Updated: 2024/11/06 10:08:01 by juan-ant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_tokensize(t_token *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		i ++;
		lst = lst->next;
	}
	return (i);
}

t_token	*ft_tokentnew(char *type, char *content, char *param, char *child)
{
	t_token	*list;

	list = malloc(sizeof(t_token));
	if (list == NULL)
		return (0);
	list->type = type;
	list->param = param;
	list->content = content;
	list->child = child;
	return (list);
}

t_token	*ft_tokenlast(t_token *lst, int mode)
{
	if (lst == NULL)
		return (lst);
	if (mode == 0)
		while (lst->next != NULL)
			lst = lst->next;
	if (mode == 1)
		while (lst->param != NULL)
			lst = lst->param;
	if (mode == 2)
		while (lst->child != NULL)
			lst = lst->child;
	return (lst);
}

t_token	*ft_tokenadvance(t_token *lst, int advance)
{
	if (lst == NULL)
		return (lst);
	while (advance != 0)
	{
		if (lst->next != NULL)
			lst = lst->next;
			advance --;
	}
	return (lst);
}

void	ft_tokenadd_back(t_token **lst, t_token *new)
{
	if (lst[0] != NULL)
		ft_plstlast(lst[0])->next = new;
	else
		lst[0] = new;
}
