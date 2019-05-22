/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:21:54 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/13 18:34:02 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				fresh[i] = f(i, s[i]);
			return (fresh);
		}
	}
	return (NULL);
}
