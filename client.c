/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:30:55 by esever            #+#    #+#             */
/*   Updated: 2025/01/19 13:53:26 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}

static void	send_signal(pid_t id, char *message)
{
	int		i;
	int		j;
	char	result;

	i = 0;
	while (message[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			result = (message[i] >> j) & 1;
			if (result == 1)
				kill(id, SIGUSR1);
			else if (result == 0)
				kill(id, SIGUSR2);
			usleep(155);
			j--;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_id;

	if (ac == 3)
	{
		server_id = ft_atoi(av[1]);
		send_signal(server_id, av[2]);
	}
	else
		write(1, "Gerekli argüman sayısı girilmedi !!", 35);
	return (0);
}