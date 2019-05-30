/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:33:01 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/13 18:28:31 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (len != 0)
	{
		if (dst > src)
		{
			while (len-- != 0)
				((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
		else
		{
			while (i < len)
			{
				((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
				++i;
			}
		}
	}
	return (dst);
}
