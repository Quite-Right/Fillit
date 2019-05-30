/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:52:02 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/12 18:56:35 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list *)(malloc(sizeof(t_list)));
	if (new)
	{
		if (!(content))
		{
			new->content = NULL;
			new->content_size = 0;
			new->next = NULL;
			return (new);
		}
		else
		{
			new->content = (void *)(malloc(content_size));
			if (new->content)
			{
				new->content = ft_memcpy(new->content, content, content_size);
				new->content_size = content_size;
				new->next = NULL;
				return (new);
			}
		}
	}
	return (NULL);
}
