/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kturnips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:05:42 by kturnips          #+#    #+#             */
/*   Updated: 2019/04/05 20:31:01 by kturnips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int				flag;
	unsigned int	bn;

	bn = n;
	flag = 1;
	if (n < 0)
	{
		bn = -n;
		ft_putchar('-');
	}
	while ((n / 10) != 0)
	{
		flag = flag * 10;
		n /= 10;
	}
	while (flag >= 1)
	{
		ft_putchar(bn / flag + '0');
		bn = bn - (bn / flag) * flag;
		flag = flag / 10;
	}
}
