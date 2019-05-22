/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:40:12 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/09 18:00:16 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		new = (char *)(malloc(sizeof(char) * (ft_strlen(s1) +
						ft_strlen(s2) + 1)));
		if (new)
		{
			while (*s1)
				new[i++] = *s1++;
			while (*s2)
				new[i++] = *s2++;
			new[i] = '\0';
			return (new);
		}
	}
	return (NULL);
}
