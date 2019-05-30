/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:16:57 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/11 18:24:59 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*only_symbols(void)
{
	char *new;

	new = (char *)(malloc(sizeof(char) * 1));
	if (new)
	{
		*new = '\0';
		return (new);
	}
	return (NULL);
}

static char	*not_only_symbols(size_t j, size_t i, char const *s)
{
	char	*new;
	size_t	n;

	n = 0;
	new = (char *)(malloc(sizeof(char) * (ft_strlen(s) - j + 1)));
	if (new)
	{
		while (n < (ft_strlen(s) - j))
			new[n++] = s[i++];
		new[n] = '\0';
		return (new);
	}
	return (NULL);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s)
	{
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
			i++;
		if (ft_strlen(s) == i)
			return (only_symbols());
		else
		{
			while (s[ft_strlen(s) - 1 - j] == '\n' || s[ft_strlen(s) - 1 - j]
			== ' ' || s[ft_strlen(s) - 1 - j] == '\t')
				j++;
			j += i;
			return (not_only_symbols(j, i, s));
		}
		return ((char *)s);
	}
	return (NULL);
}
