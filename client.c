/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:42:28 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/03 10:34:58 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	ft_printf("client: %c\n", c);
	while (bit < 8)
	{
		ft_printf("%d", ((c >> (7 - bit)) & 1) == 1);
		if (((unsigned char)(c >> (7 - bit)) & 1) == 0)
			kill(pid, SIGUSR1);
		else if (((unsigned char)(c >> (7 - bit)) & 1) == 1)
			kill(pid, SIGUSR2);
		usleep(50);
		bit++;
	}
	ft_printf("\n");
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
