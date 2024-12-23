/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaciftci <yaciftci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:40:37 by yaciftci          #+#    #+#             */
/*   Updated: 2024/12/17 14:42:49 by yaciftci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int	d;
	int	s;

	d = 1;
	s = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
	{
		d = d * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '-' || *str == '+')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		s = (s * 10);
		s = s + (*str - '0');
		str++;
	}
	return (s * d);
}

static void	f(char *str, int pid)
{
	int	i;
	int	c;

	i = 0;
	if (!str || str[i] == '\0')
	{
		return ;
	}
	while (str[i])
	{
		c = 7;
		while (c >= 0)
		{
			if ((str[i] >> c) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			c--;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc > 1)
	{
		pid = ft_atoi(argv[1]);
		f(argv[2], pid);
	}
}
