/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:50:01 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/15 17:32:12 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include <signal.h>

int	recursive_power(int n, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (n * recursive_power(n, power - 1));
}

char	*create_message(char *message, char letter)
{
	int		i;
	char	*new;

	i = -1;
	new = malloc((ft_strlen(message) + 2) * sizeof(char));
	if (!new)
	{
		free(message);
		exit (0);
	}
	while (message[++i])
		new[i] = message[i];
	new[i++] = letter;
	new[i] = '\0';
	free(message);
	return (new);
}

void	sig_handler(int signum)
{
	static int		letter = 0;
	static int		bit = 0;
	static char		*message;

	if (signum == SIGUSR1)
		letter = letter + 0;
	else if (signum == SIGUSR2)
		letter = letter + (1 * recursive_power(2, 7 - bit));
	bit++;
	if (!message)
		message = ft_strdup("");
	if (!message)
		exit (0);
	if (bit == 8)
	{
		message = create_message(message, letter);
		if (letter == '\0')
		{
			ft_printf("%s\n", message);
			free(message);
			message = NULL;
		}
		bit = 0;
		letter = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("PID %d\n", pid);
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	action.sa_handler = sig_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		usleep(50);
	return (0);
}
