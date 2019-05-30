/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:11:28 by kturnips          #+#    #+#             */
/*   Updated: 2019/02/05 19:17:55 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int index_d;
	int index_s;

	index_s = 0;
	index_d = 0;
	while (dest[index_d] != '\0')
		index_d++;
	while (src[index_s] != '\0' && index_s < nb)
	{
		dest[index_d + index_s] = src[index_s];
		index_s++;
	}
	dest[index_d + index_s] = '\0';
	return (dest);
}
