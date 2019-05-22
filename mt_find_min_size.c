#include "fillit.h"
#include <stdio.h>

int main(void) {
	int i;

	i = 0;
	while (++i < 27)
		printf("%d <= %d\n", i * 4, find_min_size(i) * find_min_size(i));
	return (0);
}

 //gcc mt_find_min_size.c map_creator.c fillit_error.c -Wall -Wextra -Werror -
 //команда для компиляции
