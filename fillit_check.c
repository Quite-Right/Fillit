/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:00:18 by kturnips          #+#    #+#             */
/*   Updated: 2019/05/19 17:00:24 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

/* на вход функция получает номер элемента тетрамины и тетрамину в виде строки
из 16 символов, результатом функции является количество связей конкретного
элемента, количеством связей конкретного элемента считается количесво граничих
с элементом '*' */

int		check_connections(int i, char *cur_tetr)
{
	int result;

	result = 0;
	if (i + 1 < 16 && cur_tetr[i + 1] == '#')
		++result;
	if (i - 1 > -1 && cur_tetr[i - 1] == '#')
		++result;
	if (i + 4 < 16 && cur_tetr[i + 4] == '#')
		++result;
	if (i - 4 > -1 && cur_tetr[i - 4] == '#')
		++result;
	return (result);
}

/* на вход в функцию подается текущая тетрамина, в функции проверяется
количество связей в тетрамине (6/8), а также количество '*' */

int check_curent_tetr(char *cur_tetr)
{
		int i;
		int j;
		int k;

		i = -1;
		j = 0;
		k = 0;
		while (cur_tetr[++i]) {
			if (cur_tetr[i] == '#')
			{
				++j;
				k += check_connections(i, cur_tetr);
			}
		}
		if (j != 4 || (k != 6 && k != 8))
			return (-1);
		return (0);
}

/* функция на вход получает считанную строку и массив с  тетраминами (пока не
заполненный), проверяет строку на количество считанных строк и выделяет память
для нужного количества тетрамин */

//size_t

char **create_tetr_array(char **input, char** tetr)
{
	int i;
	int j;

	j = -1;
	i = ft_strlen(*input);

	if (i == 0 || i % 16 != 0)
		fillit_error();
	if (!(tetr = (char **)(malloc(sizeof(char *) * (i % 16 + 1)))))
		fillit_error();
	while (++j < i / 16)
	{
		if (!(tetr[j] = ft_strsub(*input, j * 16, 16)))
			fillit_error();
		if (check_curent_tetr(tetr[j]) != 0)
			fillit_error();
	}
	free (*input);
	return (tetr);
}

/* функция на вход получает строку, и ее номер, проверяет строку на длинну и
содержащиеся в ней символы (должны быть только '.' и '*') */

//size_t?

int	check_curent_line(char *line, int line_number)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
			return (-1);
		++i;
	}
	if ((line_number % 5 == 0 && i != 0) || (line_number % 5 != 0 && i != 4))
		return (-1);
	return (0);
}

/* функция на вход получает fd, а также будущий массив тетрамин,
считывает весь файл, выполняет проверку на gnl (включая срабатывания маллока
внутри gnl) и проверку каждой из текущих строк, записывает все прочтенные
символы, кроме /n в одну строку, которую передает в след функцию проверки,
в случае если произошла ошибка на этапе вызова функции gnl, возвращает -1,
что вызовет функцию ft_error() */

//free (line) -> ft_memdel(line)
//ft_strnew(0/1)

char **fillit_check(int fd, char **tetr)
{
	char *input;
	char *temp;
	char *line;
	int i;
	int j;

	j = 0;
	if (!(input = ft_strnew(0)))
		fillit_error();
	while ((i = get_next_line(fd, &line)) == 1)
	{
		if (check_curent_line(line, ++j) != 0)
			fillit_error();
		if (!(temp = ft_strjoin(input, line)))
			fillit_error();
		free(input);
		input = temp;
		//temp = NULL?
		if (*line)
			free(line);
	}
	if (j % 5 != 4 || i != 0)
		fillit_error();
	return (create_tetr_array(&input, tetr));
}
