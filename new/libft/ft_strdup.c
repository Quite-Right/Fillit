/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:52:15 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/07 14:32:33 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	i;

	i = -1;
	result = (char *)(malloc(sizeof(char) * (ft_strlen(s1) + 1)));
	if (result)
	{
		while (*s1)
		{
			result[++i] = *s1;
			s1++;
		}
		result[++i] = '\0';
		return (result);
	}
	return (NULL);
}
