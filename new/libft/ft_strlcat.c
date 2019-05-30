/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:16:31 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/11 16:55:33 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	result;
	char	*d;

	d = dst;
	result = 0;
	while (*d && size != 0)
	{
		++d;
		--size;
	}
	result = d - dst;
	dst += result;
	if (size == 0)
		return (result + ft_strlen(src));
	result += ft_strlen(src);
	while (*src && size-- != 1)
	{
		*dst = *src;
		++dst;
		++src;
	}
	*dst = '\0';
	return (result);
}
