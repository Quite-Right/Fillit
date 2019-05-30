/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 13:53:36 by kturnips          #+#    #+#             */
/*   Updated: 2019/05/29 21:20:39 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	create_cur_tetr(t_tetr *cur, char *buf, int s_n)
{
	char cur_let;
	int str_num;

	str_num = -1;
	cur_let = 'A';
	while (--s_n)
		++cur_let;
	cur->next = (t_tetr *)(ft_memalloc(sizeof(t_tetr)));
	cur->letter = cur_let;
	cur->tetr = NULL;
	if (!(cur->tetr = (char **)(malloc(sizeof(char *) * 5))))
		fillit_error();
	(cur->tetr)[4] = NULL;
	while (++str_num < 4)
		if (!((cur->tetr)[str_num] = ft_strsub(buf, str_num * 5, 4)))
			fillit_error();
}

static int	check_connections(int i, char *cur_tetr)
{
	int result;

	result = 0;
	if (i + 1 < 19 && cur_tetr[i + 1] == '#')
		++result;
	if (i - 1 > -1 && cur_tetr[i - 1] == '#')
		++result;
	if (i + 5 < 19 && cur_tetr[i + 5] == '#')
		++result;
	if (i - 5 > -1 && cur_tetr[i - 5] == '#')
		++result;
	return (result);
}


static void check_buf(int r_s, char *buf, int s_n)
{
	int i;
	int connections;

	connections = 0;
	i = -1;
	if ((s_n >= 27) || (r_s != 20 && r_s != 21))
		fillit_error();
	if	((r_s == 21 && buf[20] && buf[20] != '\n'))
		fillit_error();
	if (r_s == 21)
		--r_s;
	while (++i < r_s)
	{
		if (i % 5 == 4 && buf[i] != '\n')
			fillit_error();
		else if (i % 5 != 4)
		{
			if (buf[i] == '#')
				connections += check_connections(i, buf);
			if (buf[i] != '.' && buf[i] != '#')
				fillit_error();
		}
	}
	if (connections != 6 && connections != 8)
		fillit_error();
}

static int create_t_tetr(t_tetr *begin, int fd)
{
	char	*buf;
	t_tetr	*temp;
	int		struct_num;
	int		read_symbols;
	int		k;

	k = 0;
	temp = begin;
	struct_num = 0;
	if (!(buf = ft_strnew(21)))
		fillit_error();
	while ((read_symbols = read(fd, buf, 21)) > 0)
	{
		++struct_num;
		k += read_symbols;
		check_buf(read_symbols, buf, struct_num);
		create_cur_tetr(temp, buf, struct_num);
		temp = temp->next;
	}
	ft_memdel((void *)temp);
	if (read_symbols != 0 || struct_num == 0 || k % 21 != 20)
		fillit_error();
	ft_strdel(&buf);
	return (struct_num);
}

/* начало программы, программа получает на вход название файла и пытается его
открыть, в случае, если программа получила больше или меньше, чем 1 аргумент,
производится вывод usage, в случае если считывание не удалось - ошибка, также вызываются функции по проверке и
созданию структуры тетрамин и карты, затем передает результаты в функцию поиска решения, после чистит все*/

int		main(int argc, char **argv)
{
	int		fd;
	char	**map;
	int		map_range;
	t_tetr	*begin;
	int tetr_amount;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
			fillit_error();
		begin =(t_tetr *)(ft_memalloc(sizeof(t_tetr)));
		tetr_amount = create_t_tetr(begin, fd);
		map_range = find_min_size(tetr_amount);
		map = create_map(map_range);
        //fillit_find_solution(map, map_range, begin->next, tetr_amount);
        delete_the_map(map);
		clean_the_struct(begin);
		if (close(fd) != 0)
			fillit_error();
	}
	else
		write(1, "fillit source_file\n", 19);
	return (0);
}
