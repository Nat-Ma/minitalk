/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:20:51 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 23:21:17 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void signal_handler(int signum)
{
	ft_printf("Received SIGINT !\n", signum);
	exit(0);
}

int	main(void)
{
	pid_t pid;

	pid = getpid();
	ft_printf("pid - %d\n", pid);

	struct sigaction action;
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	sigaction(SIGUSR1, &action, NULL);
	while (1)
	{
	}
	// display its PID
	// create endless loop to receive signals any time
	// receive the actual signal
	// decrypt the signal
	// for each SIGUSR1 and SIGUSR2 create action
	return (0);
}
