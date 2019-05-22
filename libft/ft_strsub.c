/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:38:06 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/05 17:21:14 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (s)
	{
		i = 0;
		sub = (char *)(malloc(sizeof(char) * (len + 1)));
		if (sub)
		{
			while (i < len)
			{
				sub[i] = s[start + i];
				++i;
			}
			sub[i] = '\0';
			return (sub);
		}
	}
	return (NULL);
}
