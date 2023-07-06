/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:02:51 by srachdi           #+#    #+#             */
/*   Updated: 2023/04/08 13:17:11 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int	is_numiric(char *s)
{
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	if (*s == '+')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

void	ft_send_bit(pid_t pid, char input)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((input & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	ft_send_str(pid_t pid, char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		ft_send_bit(pid, input[i]);
		i++;
	}
	ft_send_bit(pid, '\n');
	ft_send_bit(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3 && argv[2][0] != '\0' && is_numiric(argv[1]))
	{
		pid = ft_atoi(argv[1]);
		ft_send_str(pid, argv[2]);
	}
	else
	{
		ft_putstr_fd("Error: wrong format.\n", 1);
		ft_putstr_fd("Try: ./client [PID] [MESSAGE]\n", 1);
	}
	return (0);
}
