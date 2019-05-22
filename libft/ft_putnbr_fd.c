/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:20:01 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/09 18:02:05 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				flag;
	unsigned int	bn;

	bn = n;
	flag = 1;
	if (n < 0)
	{
		bn = -n;
		ft_putchar_fd('-', fd);
	}
	while ((n / 10) != 0)
	{
		flag = flag * 10;
		n /= 10;
	}
	while (flag >= 1)
	{
		ft_putchar_fd((bn / flag + '0'), fd);
		bn = bn - (bn / flag) * flag;
		flag = flag / 10;
	}
}
