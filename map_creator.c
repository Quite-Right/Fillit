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

/* на вход функция получает количество тетрамин и находит размерность карты,
способной вместить все тетрамины, количество тетрамин считается верным (1 - 26) */

int	find_min_size(int count)
{
	int size;

	size = 2;
	while (size * size < count)
		++size;
	return (size);
}

/* на вход функция получает размерность карты, которую надо создать и
пытается создать карту,
способную вместить все тетрамины, количество тетрамин считается верным (1 - 26) */

//посмотреть на утечки в случае fillit_error
//проверить size/size + 1

char **create_map(int size)
{
	char **map;
	int j;
	int i;

	i = -1;
	if (!(map = (char **)(malloc(sizeof(char *)) * (size + 1))))
		fillit_error();
	while (++i < size)
	{
		j = -1;
		if (!(map[i] = (char *)(malloc(sizeof(char) * (size + 1))))
			fillit_error();
		while(++j < size)
			map[i][j] = '.';
		map[i][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

/* на вход функция получает текущую размерность карты, например если сейчас
карта 2x2, то размерность - 2 и текущую карту, возвращает карту с размерностью на 1 больше
и чистит старую карту */

//в случае утечек проверка на <= size

char **enlarge_map(int size, char **current_map)
{
	int i;
	char **result;

	i = -1;
	while (++i < size)
	{
		free(current_map[i]);
		current_map[i] = NULL;
	}
	free(current_map);
	current_map = NULL;
	return(create_map(size + 1))
}
