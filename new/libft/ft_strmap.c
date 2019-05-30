/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:19:27 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/13 18:33:48 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*fresh;

	if (s && f)
	{
		i = ft_strlen(s);
		fresh = (char *)(malloc(sizeof(char) * (i + 1)));
		if (fresh)
		{
			fresh[i] = '\0';
			while (i-- != 0)
				fresh[i] = f(s[i]);
			return (fresh);
		}
	}
	return (NULL);
}
