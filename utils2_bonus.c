/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:23:31 by srachdi           #+#    #+#             */
/*   Updated: 2023/04/08 13:24:53 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	reset(t_data *g_data)
{
	if (g_data->string)
		free(g_data->string);
	g_data->string = NULL;
	g_data->cl_id = 0;
	g_data->string_len = 0;
	g_data->octet = 0;
	g_data->i = 0;
	g_data->current_bit = 0;
	g_data->flag = 0;
}

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
