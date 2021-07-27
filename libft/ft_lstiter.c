/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:08:20 by vkuklys           #+#    #+#             */
/*   Updated: 2021/07/16 21:43:14 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (lst == NULL || (*f) == NULL)
		return ;
	tmp = lst;
	while (tmp->next != NULL)
	{
		(*f)(tmp->content);
		tmp = tmp->next;
	}
	(*f)(tmp->content);
}
