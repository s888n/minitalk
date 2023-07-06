/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:09:34 by srachdi           #+#    #+#             */
/*   Updated: 2023/03/18 14:40:39 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_g
{
	char	tmp;
	char	bit;
	int		cid;
}	t_g;

int			ft_isdigit(char c);
int			ft_atoi(const char *str);
void		ft_putnbr_fd(int n, int fd);
void		rec_putnbr(int nb, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_send_bit(pid_t pid, char input);
void		ft_send_str(pid_t pid, char *input);
void		ft_pid_print(pid_t pid);
void		ft_handler(int signal, siginfo_t *info, void *context);
int			is_numiric(char *s);
#endif
