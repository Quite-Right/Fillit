/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:49:55 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/07 19:00:07 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *result;

	result = (char *)s;
	while (*result)
	{
		if (*result == ((unsigned char)c))
		{
			return (result);
		}
		++result;
	}
	if (*result == c)
		return (result);
	return (NULL);
}
