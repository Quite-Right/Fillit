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

<<<<<<< HEAD
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
=======
/* на вход функция получает количество тетрамин и пытается создать карту,
>>>>>>> e5bf8b6ceda497756635bb7a7e9b24d64e606a7b
способную вместить все тетрамины, количество тетрамин считается верным (1 - 26) */

//посмотреть на утечки в случае fillit_error
//проверить size/size + 1

<<<<<<< HEAD
char **create_map(int size)
{
	char **map;
	int j;
	int i;

	i = -1;
=======
char **create_map(int count)
{
	int size;
	char **map;
	int i;

	i = -1;
	size = 2;
	while (size * size < count)
		++size;
>>>>>>> e5bf8b6ceda497756635bb7a7e9b24d64e606a7b
	if (!(map = (char **)(malloc(sizeof(char *)) * (size + 1))))
		fillit_error();
	while (++i < size)
	{
<<<<<<< HEAD
		j = -1;
		if (!(map[i] = (char *)(malloc(sizeof(char) * (size + 1))))
			fillit_error();
		while(++j < size)
			map[i][j] = '.';
		map[i][j] = '\0';
=======
		if (!(map[i] = (char *)(malloc(sizeof(char) * (size + 1))))
			fillit_error();
>>>>>>> e5bf8b6ceda497756635bb7a7e9b24d64e606a7b
	}
	map[i] = NULL;
	return (map);
}
<<<<<<< HEAD

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
=======
>>>>>>> e5bf8b6ceda497756635bb7a7e9b24d64e606a7b
