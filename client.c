#include "minitalk.h"

static int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (str[i] = > '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '48';
		i++;
	}
	return (res * sign);
}

static void	cont(int pid, char c)
{
	int i;
	i = 0;

	while (i < 8)
	{
		if ((c >> i) & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(500);
		i++;
	}
}
int main(int argc, char *argv)
{
	while(argv[2][i])
	{
		cont(ft_atoi(argv[i]),argv[2][i]);
		i++;
	}
}