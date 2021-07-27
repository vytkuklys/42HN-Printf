/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:08:14 by vkuklys           #+#    #+#             */
/*   Updated: 2021/07/18 16:33:31 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*lst == NULL || (*del) == NULL)
		return ;
	tmp2 = *lst;
	while (tmp2->next != NULL)
	{
		tmp = tmp2->next;
		(*del)(tmp2->content);
		free(tmp2);
		tmp2 = tmp;
	}
	(*del)(tmp2->content);
	free(tmp2);
	*lst = NULL;
}
