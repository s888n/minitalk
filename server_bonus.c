/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 01:44:01 by srachdi           #+#    #+#             */
/*   Updated: 2023/04/08 12:50:33 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_data	g_data;

static void	print_and_reset(void)
{
	ft_putstr_fd(g_data.string, 1);
	ft_putchar_fd('\n', 1);
	reset(&g_data);
}

void	get_len(int signal)
{
	if (signal == SIGUSR2)
		g_data.string_len |= 1 << g_data.current_bit;
	if (g_data.current_bit == 31)
	{
		g_data.flag = 1;
		g_data.string = (char *) malloc((g_data.string_len + 1) * sizeof(char));
		if (!(g_data.string))
		{
			reset(&g_data);
			return ;
		}
		g_data.string_len = 0;
		g_data.current_bit = 0;
	}
	else
		(g_data.current_bit)++;
}

void	get_char(int signal, pid_t cid)
{
	if (signal == SIGUSR2)
		g_data.octet |= 1 << g_data.current_bit;
	if (g_data.current_bit == 7)
	{
		g_data.string[g_data.i] = (char)g_data.octet;
		(g_data.i)++;
		g_data.current_bit = 0;
		if (g_data.octet == '\0')
		{
			print_and_reset();
			kill(cid, SIGUSR1);
		}
		g_data.octet = 0;
		return ;
	}
	(g_data.current_bit)++;
}

void	get_signals(int signal, siginfo_t *info, void *context)
{
	if (!g_data.cl_id)
		g_data.cl_id = info->si_pid;
	if (g_data.cl_id != info->si_pid)
		reset(&g_data);
	(void) context;
	if (g_data.flag == 0)
		get_len(signal);
	else
		get_char(signal, g_data.cl_id);
	g_data.cl_id = info->si_pid;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("Error: worng format.\n", 1);
		ft_putstr_fd("Try: ./server\n", 1);
		return (0);
	}
	reset(&g_data);
	sa.sa_sigaction = get_signals;
	sa.sa_flags = SA_RESTART;
	g_data.flag = 0;
	g_data.octet = 0;
	g_data.current_bit = 0;
	ft_putstr_fd("Server pid is : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
