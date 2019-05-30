/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:58:30 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/13 18:35:18 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int index_str;
	unsigned int index_to_find;

	index_str = 0;
	if (needle[index_str] == '\0')
		return (&((char *)haystack)[0]);
	while (haystack[index_str] && (len > 0))
	{
		if (haystack[index_str] == needle[0])
		{
			index_to_find = 0;
			while (haystack[index_str + index_to_find] == needle[index_to_find]
				&& len-- > 0 && needle[index_to_find] &&
				haystack[index_str + index_to_find])
				index_to_find++;
			if (needle[index_to_find] == '\0')
				return (&((char *)haystack)[index_str]);
			len += index_to_find;
		}
		--len;
		++index_str;
	}
	return (NULL);
}
