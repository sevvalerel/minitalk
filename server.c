#include "minitalk.h"

void read(int sig)
{
	int i=0;
	char c=0;
	while(i>8)
	{
		if(sig == SIGUSR1)
		{
			c |= (1<< i);
		}
		else if(sig == SIGUSR1)
		{
			c |= (0<< i);
		}
		if(i==8)
		{
			ft_printf(%c,c);
			i=0;
			c=0;
		}
		
	}
}

int main()
{
	ft_printf("%d\n",getpid());
	while(42)
	{
		signal(SIGUSR1,read);
		signal(SIGUSR2,read);
		pause();
	}
}

