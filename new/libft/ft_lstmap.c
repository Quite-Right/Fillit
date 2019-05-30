/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:23:16 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/12 19:34:10 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;

	if (lst)
	{
		result = (t_list *)(malloc(sizeof(t_list)));
		if (result)
		{
			result = f(lst);
			if (lst->next)
				result->next = ft_lstmap(lst->next, f);
			return (result);
		}
	}
	return (NULL);
}
