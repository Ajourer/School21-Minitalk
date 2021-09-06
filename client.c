#include "minitalk.h"

void	sending_signals(int pid, char *sym, size_t len)
{
	int		count;
	size_t	i;

	i = 0;
	count = 128;
	while (i <= len)
	{
		while (count >= 1)
		{
			if (count & sym[i])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			count /= 2;
			usleep(100);
		}
		count = 128;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		sending_signals(pid, argv[2], ft_strlen(argv[2]));
	}
	else
	{
		write(1, "ERROR!\n", 7);
		ft_putstr_fd("Correct input: ./client \"server PID\" \"message\"\n", 1);
	}
	return (0);
}
