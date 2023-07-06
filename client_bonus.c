/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 01:39:07 by srachdi           #+#    #+#             */
/*   Updated: 2023/04/08 12:57:06 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	msg_recieved(int signal, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("Message Recieved by the Server!\n", 1);
		exit(0);
	}
}

void	send_strlen(pid_t pid, int len)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (len & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		i++;
		usleep(100);
	}
}

void	send_signal(pid_t pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **av)
{
	pid_t				pid;
	char				*str;
	struct sigaction	sa;

	if (argc == 3 && av[2][0] != '\0' && is_numiric(av[1]))
	{
		sa.sa_sigaction = msg_recieved;
		sa.sa_flags = SA_RESTART;
		pid = ft_atoi(av[1]);
		str = av[2];
		send_strlen(pid, ft_strlen(str));
		while (*str)
			send_signal(pid, *str++);
		sigaction(SIGUSR1, &sa, NULL);
		send_signal(pid, *str);
		pause();
	}
	else
	{
		ft_putstr_fd("Error: wrong format.\n", 1);
		ft_putstr_fd("Try: ./client [PID] [MESSAGE]\n", 1);
	}
	return (0);
}
