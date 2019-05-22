/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:44:53 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/09 17:58:30 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;
	size_t	i;

	i = 0;
	if (size)
	{
		new = malloc(size);
		if (new)
		{
			while (i != size)
				((unsigned char *)new)[i++] = 0;
			return (new);
		}
	}
	return (0);
}
