/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:14:35 by kturnips          #+#    #+#             */
/*   Updated: 2019/05/19 14:14:36 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* на вход функция получает количество тетрамин и пытается создать карту,
способную вместить все тетрамины, количество тетрамин считается верным (1 - 26) */

//посмотреть на утечки в случае fillit_error
//проверить size/size + 1

char **create_map(int count)
{
	int size;
	char **map;
	int i;

	i = -1;
	size = 2;
	while (size * size < count)
		++size;
	if (!(map = (char **)(malloc(sizeof(char *)) * (size + 1))))
		fillit_error();
	while (++i < size)
	{
		if (!(map[i] = (char *)(malloc(sizeof(char) * (size + 1))))
			fillit_error();
	}
	map[i] = NULL;
	return (map);
}
