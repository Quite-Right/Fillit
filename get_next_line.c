/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:08:32 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/27 17:49:40 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		create_line(char **line, int i, char **balance)
{
	char *tmp;

	i = 0;
	if (**balance && *balance)
	{
		while ((*balance)[i] && (*balance)[i] != '\n')
			++i;
		if (!(*line = ft_strsub(*balance, 0, i)))
			return (-1);
		if (i != (int)ft_strlen(*balance))
		{
			if (!(tmp = ft_strsub(*balance, i + 1, (ft_strlen(*balance) - i))))
				return (-1);
			free(*balance);
			*balance = tmp;
		}
		else
		{
			free(*balance);
			*balance = NULL;
		}
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*balance[MAX_FD + 1];
	int			red;
	char		*tmp_fir;
	int			i;

	if (fd < 0 || BUFF_SIZE < 1 || fd > MAX_FD || line == NULL)
		return (-1);
	if (!(balance[fd]))
		if (!(balance[fd] = ft_strnew(0)))
			return (-1);
	while ((red = read(fd, buf, BUFF_SIZE)) > 0)
	{
		i = 0;
		buf[red] = '\0';
		while (buf[i] && buf[i] != '\n')
			++i;
		if (!(tmp_fir = ft_strjoin(balance[fd], buf)))
			return (-1);
		free(balance[fd]);
		balance[fd] = tmp_fir;
		if (i != red)
			return (create_line(line, i, &balance[fd]));
	}
	return (red < 0 ? -1 : create_line(line, i, &balance[fd]));
}
