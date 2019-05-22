/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:56:39 by kturnips          #+#    #+#             */
/*   Updated: 2019/02/05 18:08:29 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int index_d;
	unsigned int index_s;

	index_s = 0;
	index_d = 0;
	while (dest[index_d] != '\0')
		index_d++;
	while (src[index_s] != '\0')
	{
		dest[index_d + index_s] = src[index_s];
		index_s++;
	}
	dest[index_d + index_s] = '\0';
	return (dest);
}
