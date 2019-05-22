#include "fillit.h"
#include <stdio.h>

int main(void) {
	int i;
	int j;
	char **map;

	i = 1;
	while (++i < 11)
	{
		printf("MAP %dx%d\n", i, i);
		j = -1;
		map = create_map(i);
		while (++j < i)
			printf("%s\n", map[j]);
		printf("ENLARGED MAP %dx%d\n", i + 1, i + 1);
		map = enlarge_map(i, map);
		j = -1;
		while (++j < i + 1)
		{
			printf("%s\n", map[j]);
			free(map[j]);
		}
		free(map);
	}
	return (0);
}

 //gcc mt_enlarge_map.c map_creator.c fillit_error.c -Wall -Wextra -Werror -
 //команда для компиляции
