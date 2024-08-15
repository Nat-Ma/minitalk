/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:42:28 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/15 17:37:30 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		//ft_printf("%d", ((c >> (7 - bit)) & 1) == 1);
		if (((unsigned char)(c >> (7 - bit)) & 1) == 0)
			kill(pid, SIGUSR1);
		else if (((unsigned char)(c >> (7 - bit)) & 1) == 1)
			kill(pid, SIGUSR2);
		usleep(50);
		bit++;
	}
}

int	main(int argv, char **argc)
{
	char	*message;
	int		pid;

	if (argv == 3)
	{
		pid = ft_atoi(argc[1]);
		message = argc[2];
		while (*message)
		{
			send_bits(pid, *message);
			message++;
		}
		send_bits(pid, '\0');
	}
	else
		ft_printf("Somewhing is wrong with your args.");
	return (0);
}
