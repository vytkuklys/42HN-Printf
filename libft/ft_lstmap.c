/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:08:31 by vkuklys           #+#    #+#             */
/*   Updated: 2021/07/19 20:44:43 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*dl)(void *))
{
	t_list	*list;
	t_list	*item;
	char	*content;
	int		len;

	if (lst == NULL)
		return (NULL);
	list = NULL;
	len = ft_lstsize(lst);
	while (len > 0)
	{
		content = (*f)(lst->content);
		item = ft_lstnew(content);
		if (item == NULL)
		{
			ft_lstclear(&list, (*dl));
			free(list);
			return (NULL);
		}
		ft_lstadd_back(&list, item);
		lst = lst->next;
		len--;
	}
	return (list);
}
