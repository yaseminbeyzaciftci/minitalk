/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaciftci <yaciftci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:41:35 by yaciftci          #+#    #+#             */
/*   Updated: 2024/12/17 14:01:14 by yaciftci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putpid(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
		n = -n;
	}
	if (n >= 10)
		ft_putpid(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

static void	ft_handle(int sig)
{
	static int	a;
	static int	count;

	a <<= 1;
	if (sig == SIGUSR2)
		a |= 1;
	count++;
	if (count == 8)
	{
		write(1, &a, 1);
		count = 0;
	}
}

int	main(void)
{
	pid_t	a;

	a = getpid();
	ft_putpid(a);
	signal(SIGUSR1, ft_handle);
	signal(SIGUSR2, ft_handle);
	while (1)
		continue ;
}
