#include "minitalk.h"

static t_str	g_str;

void	getting_signals(int sig)
{
	if (sig == SIGUSR1)
		g_str.s |= g_str.count;
	g_str.count /= 2;
	if (g_str.count < 1)
	{
		write(1, &g_str.s, 1);
		if (!g_str.s)
			write(1, "\n", 1);
		g_str.s = 0;
		g_str.count = 128;
	}
}

int	main(void)
{
	g_str.s = 0;
	g_str.count = 128;
	write(1, "server pid : ", 13);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, getting_signals);
	signal(SIGUSR2, getting_signals);
	while (1)
		pause();
}
