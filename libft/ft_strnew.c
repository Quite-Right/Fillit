/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:28:40 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/05 17:21:40 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	++size;
	new = (char *)(malloc(sizeof(char) * (size)));
	if (new)
	{
		while (i < size)
			new[i++] = '\0';
		return (new);
	}
	return (NULL);
}
