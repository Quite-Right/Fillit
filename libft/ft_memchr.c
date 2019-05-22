/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:37:24 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/07 14:27:39 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (n-- != 0)
	{
		if (((unsigned char *)s)[i] == ((unsigned char)c))
			return (&((void *)s)[i]);
		++i;
	}
	return (NULL);
}
