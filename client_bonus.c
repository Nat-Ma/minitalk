/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:42:28 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/03 11:09:00 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	send_bits(int pid, char c)
{
	int	bit;
	int	res;

	bit = 0;
	res = 0;
	while (bit < 8)
	{
		if (((unsigned char)(c >> (7 - bit)) & 1) == 0)
			res += kill(pid, SIGUSR1);
		else if (((unsigned char)(c >> (7 - bit)) & 1) == 1)
			res += kill(pid, SIGUSR2);
		usleep(20);
		bit++;
	}
	return (res);
}

int	main(int argv, char **argc)
{
	char	*message;
	int		pid;
	size_t	res;

	if (argv == 3)
	{
		res = 0;
		pid = ft_atoi(argc[1]);
		message = argc[2];
		while (*message)
		{
			res += send_bits(pid, *message);
			message++;
		}
		send_bits(pid, '\0');
		if (res == 0)
			ft_printf("Server received message!\n");
	}
	else
		ft_printf("Somewhing is wrong with your args.");
	return (0);
}
