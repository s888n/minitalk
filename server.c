/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:06:08 by srachdi           #+#    #+#             */
/*   Updated: 2023/04/08 13:23:04 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_g	g_var;

void	reset(void)
{
	g_var.bit = 0;
	g_var.tmp = 0;
	g_var.cid = 0;
}

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (g_var.cid != info->si_pid)
		reset();
	if (signal == SIGUSR1)
		g_var.tmp |= (1 << g_var.bit);
	g_var.bit++;
	if (g_var.bit == 8)
	{
		write(1, &g_var.tmp, 1);
		reset();
	}
	g_var.cid = info->si_pid;
}

void	ft_pid_print(pid_t pid)
{
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Waiting for a message...\n", 1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	reset();
	sa.sa_sigaction = ft_handler;
	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("Error: worng format.\n", 1);
		ft_putstr_fd("Try: ./server\n", 1);
		return (0);
	}
	ft_pid_print(getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
