/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:14:35 by kturnips          #+#    #+#             */
/*   Updated: 2019/05/22 14:50:34 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* на вход функция получает количество тетрамин и находит размерность карты,
способной вместить все тетрамины, количество тетрамин считается верным (1 - 26) */

int	find_min_size(int count)
{
	int size;

	size = 2;
	while (size * size < count * 4)
		++size;
	return (size);
}

/* на вход функция получает количество размерность и пытается создать карту
этой размерности (size * size) */

char **create_map(int size)
{
	char **map;
	int j;
	int i;

	i = -1;
	if (!(map = (char **)(malloc(sizeof(char *) * (size + 1)))))
		fillit_error();
	while (++i < size)
	{
		j = -1;
		if (!(map[i] = (char *)(malloc(sizeof(char) * (size + 1)))))
			fillit_error();
		while (++j < size)
			map[i][j] = '.';
		map[i][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

/* на вход функция получает текущую размерность карты, например если сейчас
карта 2x2, то размерность - 2 и текущую карту, возвращает карту с размерностью на 1 больше
и чистит старую карту */

char **enlarge_map(int size, char **current_map)
{
	int i;

	i = -1;
	while (++i < size)
	{
		free(current_map[i]);
		current_map[i] = NULL;
	}
	free(current_map);
	current_map = NULL;
	return (create_map(size + 1));
}

/* на вход функция получает указатель на начало структуры тетрамин и полностью
очищает ее */

void	clean_the_struct(t_tetr *begin) {
	int i;

	i = 0;
	if (begin->next)
		clean_the_struct(begin->next);
	if ((begin->tetr))
		while ((begin->tetr)[i])
		{
			free((begin->tetr[i]));
			++i;
		}
	if (begin->tetr)
		free((begin->tetr));
	free(begin);
}

/* на вход функция получает карту, чистит ее и меняет указатели на  NULL*/

void    delete_the_map(char **map) {
    int i;

    i = -1;
    while(map[++i])
    {
        free(map[i]);
        map[i] = NULL;
    }
    free(map);
    map = NULL;
}