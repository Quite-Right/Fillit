/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 13:53:36 by kturnips          #+#    #+#             */
/*   Updated: 2019/05/19 13:53:38 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		//fd = 0?

		if (close(fd) != 0);
			fillit_error();
		//нужна ли проверка на закрытие файла?
	}
	else
		write(1, "fillit source_file\n", 19);
	return (0);
}
