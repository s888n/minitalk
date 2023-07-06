/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 01:53:30 by srachdi           #+#    #+#             */
/*   Updated: 2023/04/08 13:19:47 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_data
{
	char	*string;
	int		string_len;
	int		octet;
	int		current_bit;
	int		i;
	int		flag;
	pid_t	cl_id;
}	t_data;

void	reset(t_data *g_data);
void	get_len(int signal);
void	get_char(int signal, pid_t cid);
void	get_signals(int signal, siginfo_t *info, void *context);
int		ft_isdigit(char c);
int		is_numiric(char *s);
void	msg_recieved(int signal, siginfo_t *info, void *context);
void	send_strlen(pid_t pid, int len);
void	send_signal(pid_t pid, unsigned char c);
int		ft_strlen(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	rec_putnbr(int nb, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
#endif
