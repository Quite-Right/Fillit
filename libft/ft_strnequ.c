/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:29:33 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/13 18:34:41 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (s1 && s2)
	{
		i = 0;
		if (n)
		{
			while (s1[i] && s2[i] && s1[i] == s2[i] && n != i)
				i++;
			if (s1[i - 1] == s2[i - 1] && n == i)
				return (1);
			else if (s1[i] == s2[i])
				return (1);
		}
		else
			return (1);
	}
	return (0);
}
