/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:28:39 by esever            #+#    #+#             */
/*   Updated: 2025/01/19 13:53:29 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putpid(pid_t n)
{
	char	c;

	if (n > 9)
	{
		ft_putpid(n / 10);
		ft_putpid(n % 10);
	}
	else
	{
		c = 48 + n;
		write(1, &c, 1);
	}
}

static void	signal_to_char(int signal)
{
	static char		c;
	static int		i;

	i++;
	if (signal == SIGUSR1)
		c = c | 1;
	if (i == 8)
	{
		write (1, &c, 1);
		i = 0;
		c = 0;
	}
	c = c << 1;
}

int	main(void)
{
	pid_t	server_id;

	server_id = getpid();
	ft_putpid(server_id);
	signal(SIGUSR1, signal_to_char);
	signal(SIGUSR2, signal_to_char);
	while (1)
	{
		pause();
	}
	return (0);
}