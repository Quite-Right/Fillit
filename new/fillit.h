/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:45:53 by kturnips          #+#    #+#             */
/*   Updated: 2019/05/29 18:06:27 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_tetr 
{ 
	char			**tetr; 
	int				len_x; 
	int				len_y; 
	char			letter;
	struct s_tetr	*next;
}				t_tetr;

void clean_the_struct(t_tetr *begin);
void    delete_the_map(char **map);
int	find_min_size(int count);
void	fillit_error(void);
char **create_map(int size);
char **enlarge_map(int size, char **current_map);

#endif
