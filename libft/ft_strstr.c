/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:56:53 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/13 18:40:37 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	index_str;
	unsigned int	index_to_find;

	index_str = 0;
	if (needle[index_str] == '\0')
		return (&((char *)haystack)[0]);
	while (haystack[index_str])
	{
		if (haystack[index_str] == *needle)
		{
			index_to_find = 1;
			while (haystack[index_str + index_to_find] == needle[index_to_find]
					&& needle[index_to_find] &&
					haystack[index_str + index_to_find])
				++index_to_find;
			if (needle[index_to_find] == '\0')
				return (&((char *)haystack)[index_str]);
		}
		++index_str;
	}
	return (NULL);
}
