/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:20:46 by nrauh             #+#    #+#             */
/*   Updated: 2024/07/28 23:40:30 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

int	*char_to_bits(char c)
{
	int	i;
	int	*bits;

	i = 8;
	bits = malloc(8 * sizeof(int));
	while (i--)
		bits[i] = (c << (7 - i) & 1);
	return (bits);
}

int	main(int argc, char**argv)
{
	char	*pid;
	char	*message;
	int		*bits;

	if (argc == 3)
	{
		(void)pid;
		message = argv[2];
		while (*message)
		{
			bits = char_to_bits('H');
			while (*bits)
				ft_printf("%d", *bits++);
			message++;
			free(bits);
		}
		// first argv is PID
		// second argv is message
		// encrypt the message via bits
		// send message to the server via PID
		// create a stop condition for server once message is finished
		return (0);
	}
	return (0);
}
